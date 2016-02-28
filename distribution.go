package main

import (
	"bytes"
	"fmt"
)

type Distribution struct {
	lines  map[rune][]string // map character to list of matching lines
	maxLen int               // max number of lines per character

	// recursive
	distributions map[rune]*Distributions // nested distributions per character
}

func NewDistribution() *Distribution {
	return &Distribution{
		lines: map[rune][]string{},
	}
}

func (d *Distribution) Add(r rune, line string) {
	d.lines[r] = append(d.lines[r], line)
	if d.maxLen < len(d.lines[r]) {
		d.maxLen = len(d.lines[r])
	}
}

// how many different characters have we seen
func (d *Distribution) Len() int {
	return len(d.lines)
}

func (d *Distribution) MaxLen() int {
	return d.maxLen
}

func (d *Distribution) Strategy() (bestStrategy *Strategy, minLoad float32) {
	bestStrategy = &Strategy{Lines: map[rune]string{}}
	total := 0
	for r, lines := range d.lines {
		if len(lines) == 1 {
			bestStrategy.Lines[r] = lines[0]
			minLoad++
			total++
		}
	}

	if d.maxLen == 1 {
		return bestStrategy, 1
	}

	if d.distributions == nil {
		return nil, 0
	}

	bestStrategy.Strategies = map[rune]*Strategy{}
	for r, distributions := range d.distributions {
		strategy, load, weight := distributions.Strategy()
		if strategy == nil {
			return nil, 0 // at least one distribution needs to go deeper
		}
		minLoad += (load + 1) * float32(weight)
		total += weight
		bestStrategy.Strategies[r] = strategy
	}

	minLoad = minLoad / float32(total)
	return bestStrategy, minLoad // all good
}

func (d *Distribution) GoDeeper() {
	if d.distributions == nil {
		d.distributions = map[rune]*Distributions{}
		for r, lines := range d.lines {
			if len(lines) == 1 {
				continue
			}

			d.distributions[r] = NewDistributions(lines)
		}
		return
	}

	for _, distributions := range d.distributions {
		distributions.GoDeeper()
	}
}

func (d Distribution) String(indent string) string {
	buffer := bytes.Buffer{}

	for r, lines := range d.lines {
		if len(lines) <= 2 {
			buffer.WriteString(fmt.Sprintf("%s%q: %d %s\n", indent, r, len(lines), lines))
		} else {
			buffer.WriteString(fmt.Sprintf("%s%q: %d\n", indent, r, len(lines)))
		}

		if d.distributions != nil && d.distributions[r] != nil {
			buffer.WriteString(fmt.Sprintf("%s", d.distributions[r].String(indent+" ")))
		}
	}

	return buffer.String()
}
