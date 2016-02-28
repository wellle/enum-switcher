package main

import (
	"bytes"
	"fmt"
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
	for r, line := range strategy.Lines {
		buffer.WriteString(fmt.Sprintf("%s%scase %s: return %d; // %s\n", indent, tab, char(r), lineIndexes[line], line))
	}

	// add recursive cases
	for r, strat := range strategy.Strategies {
		buffer.WriteString(fmt.Sprintf("%s%scase %s: %s", indent, tab, char(r), formatC(strat, lineIndexes, indent+tab)))
	}

	// close switch statement
	buffer.WriteString(fmt.Sprintf("%s%sdefault: return -1;\n", indent, tab))
	buffer.WriteString(fmt.Sprintf("%s}\n", indent))
	return buffer.String()
}

func char(r rune) string {
	if r == '\x00' {
		return `'\0'`
	}
	return fmt.Sprintf("%q", r)
}
