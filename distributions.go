package main

import (
	"bytes"
	"fmt"
	"math"
)

type Distributions struct {
	weight        int             // how many lines do we have in this distribution
	distributions []*Distribution // distribution per character index
	minLen        int             // min len of all lines
}

// create distributions form set of lines
func NewDistributions(lines []string) *Distributions {
	distributions := &Distributions{
		minLen: math.MaxInt32,
	}

	for _, line := range lines {
		distributions.AddLine(line)
	}

	return distributions
}

func (d *Distributions) AddLine(line string) {
	d.weight++

	lineLen := len(line)
	if d.minLen > lineLen {
		d.minLen = lineLen
	}

	for r, runeValue := range line {
		d.Add(r, runeValue, line)
	}
	d.Add(lineLen, '\x00', line) // add terminating zero
}

func (d *Distributions) Add(i int, r rune, line string) {
	for len(d.distributions) <= i {
		d.distributions = append(d.distributions, NewDistribution())
	}
	d.distributions[i].Add(r, line)
}

// return best strategy for found distributions
// might return nil when nothing was found yet, GoDeeper then
func (d *Distributions) Strategy() (bestStrategy *Strategy, minLoad float32, weight int) {
	minLoad = math.MaxFloat32
	for i, distribution := range d.distributions {
		if i > d.minLen {
			break
		}

		strategy, load := distribution.Strategy()
		if strategy == nil {
			continue
		}

		if minLoad > load {
			minLoad = load
			bestStrategy = strategy
			bestStrategy.Index = i
		}
	}

	return bestStrategy, minLoad, d.weight
}

// expands one more level of distributions
func (d *Distributions) GoDeeper() {
	for _, distribution := range d.distributions {
		if distribution.Len() > 1 {
			distribution.GoDeeper()
		}
	}
}

func (d *Distributions) String(indent string) string {
	buffer := bytes.Buffer{}

	minMaxLen := math.MaxInt32
	for i, distribution := range d.distributions {
		if i == d.minLen {
			break
		}

		if distribution.Len() == 1 {
			continue
		}

		buffer.WriteString(fmt.Sprintf("%sindex %d\n%s", indent, i, distribution.String(indent+" ")))

		if minMaxLen > distribution.MaxLen() {
			minMaxLen = distribution.MaxLen()
		}
	}

	return buffer.String()
}
