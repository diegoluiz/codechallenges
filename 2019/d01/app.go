package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
)

func main() {
	fmt.Printf("day 01\n")
	lines := readfile("input.txt")

	totalModulesFuel := 0
	for _, line := range lines {
		mass, _ := strconv.Atoi(line)
		fuel := calculateMass(mass)

		totalModulesFuel += fuel
	}
	fmt.Printf("p1\n")
	fmt.Println(totalModulesFuel)
}

func calculateMass(mass int) int {
	v1 := mass / 3
	v2 := int(v1)
	v3 := v2 - 2

	return v3
}

func readfile(file string) []string {
	data, err := ioutil.ReadFile(file)
	if err != nil {
		fmt.Println("File reading error", err)
		return nil
	}
	text := string(data)
	lines := strings.Split(text, "\n")
	return lines
}
