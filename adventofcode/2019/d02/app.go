package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
)

func main() {
	fmt.Printf("day 02\n")
	lines := readfile("input.txt")

	intCodesText := strings.Split(lines[0], ",")
	intCodes := []int{}

	for _, intCodeText := range intCodesText {
		i, _ := strconv.Atoi(intCodeText)
		intCodes = append(intCodes, i)
	}

	tempIntCodes := copyArray(intCodes)
	tempIntCodes[1] = 12
	tempIntCodes[2] = 2
	calculate(tempIntCodes)

	fmt.Printf("p1: ")
	fmt.Println(tempIntCodes[0])

	r := find(intCodes)
	fmt.Printf("\np2: %v", r)
}

func find(intCodes []int) int {
	v1 := 0
	v2 := 0

	for v1 = 0; v1 < 100; v1++ {
		for v2 = 0; v2 < 100; v2++ {
			tempArray := copyArray(intCodes)
			tempArray[1] = v1
			tempArray[2] = v2
			calculate(tempArray)
			if tempArray[0] == 19690720 {
				return (v1 * 100) + v2
			}
		}
		// fmt.Printf("Printing for v1: %v\n", v1)
	}

	return 0
}

func calculate(intCodes []int) {
	idx := 0
	for idx < len(intCodes) {
		if intCodes[idx] == 99 {
			break
		}

		op := intCodes[idx]
		pos1 := intCodes[idx+1]
		pos2 := intCodes[idx+2]
		pos3 := intCodes[idx+3]

		v1 := intCodes[pos1]
		v2 := intCodes[pos2]

		r := 0
		if op == 1 {
			r = v1 + v2
		}
		if op == 2 {
			r = v1 * v2
		}

		intCodes[pos3] = r
		idx = idx + 4
	}
}

func copyArray(arr []int) []int {
	newArr := []int{}
	for _, i := range arr {
		newArr = append(newArr, i)
	}
	return newArr
}

func readfile(file string) []string {
	// return []string{"1", "9", "10", "3", "2", "3", "11", "0", "99", "30", "40", "50"}

	data, err := ioutil.ReadFile(file)
	if err != nil {
		fmt.Println("File reading error", err)
		return nil
	}
	text := string(data)
	lines := strings.Split(text, "\n")
	return lines
}
