package main

import (
	"bytes"
	"fmt"
)

type Strategy struct {
	Index      int                // which index should this strategy check
	Lines      map[rune]string    // what line for which character
	Strategies map[rune]*Strategy // what substrategy for which character
}

func (strategy *Strategy) String(indent string) string {
	if strategy == nil {
		return "nil"
	}

	buffer := bytes.Buffer{}
	buffer.WriteString(fmt.Sprintf("index %d\n", strategy.Index))

	for r, line := range strategy.Lines {
		buffer.WriteString(fmt.Sprintf("%s%q -> %s\n", indent, r, line))
	}

	for r, strat := range strategy.Strategies {
		buffer.WriteString(fmt.Sprintf("%s%q -> %s", indent, r, strat.String(indent+" ")))
	}

	return buffer.String()
}
