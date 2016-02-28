package main

import (
	"bytes"
	"fmt"
	"sort"
)

const tab = "    "

func FormatC(strategy *Strategy, lineIndexes map[string]int) string {
	buffer := bytes.Buffer{}
	buffer.WriteString("int convert(char* s) {\n")
	buffer.WriteString(fmt.Sprintf("%s%s", tab, formatC(strategy, lineIndexes, tab)))
	buffer.WriteString("}\n")
	return buffer.String()
}

func formatC(strategy *Strategy, lineIndexes map[string]int, indent string) string {
	// open switch statement
	buffer := bytes.Buffer{}
	buffer.WriteString(fmt.Sprintf("switch(s[%d]) {\n", strategy.Index))

	// add simple cases
	runes := Runes{}
	for r, _ := range strategy.Lines {
		runes = append(runes, r)
	}
	sort.Sort(runes)
	for _, r := range runes {
		line := strategy.Lines[r]
		buffer.WriteString(fmt.Sprintf(
			"%s%scase %s: return %d; // %s\n",
			indent,
			tab,
			char(r),
			lineIndexes[line],
			line,
		))
	}

	// add recursive cases
	runes = Runes{}
	for r, _ := range strategy.Strategies {
		runes = append(runes, r)
	}
	sort.Sort(runes)
	for _, r := range runes {
		strat := strategy.Strategies[r]
		buffer.WriteString(fmt.Sprintf(
			"%s%scase %s: %s",
			indent,
			tab,
			char(r),
			formatC(strat, lineIndexes, indent+tab),
		))
	}

	// close switch statement
	buffer.WriteString(fmt.Sprintf("%s%sdefault: return -1;\n", indent, tab))
	buffer.WriteString(fmt.Sprintf("%s}\n", indent))
	return buffer.String()
}

type Runes []rune

func (r Runes) Len() int {
	return len(r)
}

func (r Runes) Swap(i, j int) {
	r[i], r[j] = r[j], r[i]
}

func (r Runes) Less(i, j int) bool {
	return r[i] < r[j]
}

func char(r rune) string {
	if r == '\x00' {
		return `'\0'`
	}
	return fmt.Sprintf("%q", r)
}
