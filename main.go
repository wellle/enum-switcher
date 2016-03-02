package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	var format string
	var paranoid bool
	flag.StringVar(&format, "format", "", "output format")
	flag.BoolVar(&paranoid, "paranoid", false, "handle any input")
	flag.Parse()

	// read lines
	lines := []string{}
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		lines = append(lines, line)
	}
	if err := scanner.Err(); err != nil {
		log.Panicf("failed scan %s", err)
	}

	// check there are no duplicates
	lineIndexes := map[string]int{}
	for i, line := range lines {
		if _, ok := lineIndexes[line]; ok {
			log.Panicf("found duplicate line %q", line)
		}
		lineIndexes[line] = i
	}

	if paranoid {
		strategy := paranoidStrategy(lines)
		printStategy(strategy, format, lineIndexes)
		return
	}

	// get character distributions
	distributions := NewDistributions(lines)

	// go deeper until strategy is found
	for {
		strategy, score, _ := distributions.Strategy()
		if strategy != nil {
			log.Printf("found strategy with %.2f expected checks", score)

			printStategy(strategy, format, lineIndexes)
			return
		}

		log.Printf("nothing found yet, trying harder...")
		distributions.GoDeeper()
	}
}

func paranoidStrategy(lines []string) *Strategy {
	strategy := &Strategy{
		Index: 0,
	}

	for _, line := range lines {
		strat := strategy
		for _, r := range line {
			if strat.Strategies == nil {
				strat.Strategies = map[rune]*Strategy{}
			}

			child := strat.Strategies[r]
			if child == nil {
				child = &Strategy{Index: strat.Index + 1}
				strat.Strategies[r] = child
			}

			strat = child
		}
		if strat.Strategies == nil {
			strat.Strategies = map[rune]*Strategy{}
		}

		strat.Lines = map[rune]string{'\x00': line}
	}

	return strategy
}

func printStategy(strategy *Strategy, format string, lineIndexes map[string]int) {
	if format == "c" {
		fmt.Print(FormatC(strategy, lineIndexes))
	} else {
		fmt.Print(strategy.String(" "))
	}
}
