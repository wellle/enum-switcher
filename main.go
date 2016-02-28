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
	flag.StringVar(&format, "format", "", "output format")
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

	// get character distributions
	distributions := NewDistributions(lines)

	// go deeper until strategy is found
	for {
		strategy, score, _ := distributions.Strategy()
		if strategy != nil {
			log.Printf("found strategy with %.2f expected checks", score)

			if format == "c" {
				fmt.Print(FormatC(strategy, lineIndexes))
			} else {
				fmt.Print(strategy.String(" "))
			}

			return
		}

		log.Printf("nothing found yet, trying harder...")
		distributions.GoDeeper()
	}
}
