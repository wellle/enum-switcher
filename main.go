package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

func main() {
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
	lineMap := map[string]struct{}{}
	for _, line := range lines {
		if _, ok := lineMap[line]; ok {
			log.Panicf("found duplicate line %q", line)
		}
		lineMap[line] = struct{}{}
	}

	// get character distributions
	distributions := NewDistributions(lines)

	// go deeper until strategy is found
	for {
		strategy, score, _ := distributions.Strategy()
		if strategy != nil {
			log.Printf("found strategy with %.2f expected checks", score)
			fmt.Print(strategy.String(" "))
			break
		}

		log.Printf("nothing found yet, trying harder...")
		distributions.GoDeeper()
	}
}
