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

	totalFuel := 0
	totalModulesFuel := 0
	for _, line := range lines {
		mass, _ := strconv.Atoi(line)
		fuel := calculateFuel(mass)

		fuelForFuel := calculateFuelRec(fuel)

		totalModulesFuel += fuel
		totalFuel += fuel
		totalFuel += fuelForFuel
	}
	fmt.Printf("p1: ")
	fmt.Println(totalModulesFuel)
	fmt.Printf("\np2: ")
	fmt.Println(totalFuel)
}

func calculateFuelRec(mass int) int {
	fuel := calculateFuel(mass)
	if fuel > 0 {
		fuel += calculateFuelRec(fuel)
		return fuel
	}

	return 0
}

func calculateFuel(mass int) int {
	v1 := mass / 3
	v2 := int(v1)
	v3 := v2 - 2

	return v3
}

func readfile(file string) []string {
	// return []string{"14", "1969"}
	data, err := ioutil.ReadFile(file)
	if err != nil {
		fmt.Println("File reading error", err)
		return nil
	}
	text := string(data)
	lines := strings.Split(text, "\n")
	return lines
}
