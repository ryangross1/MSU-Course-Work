package main
import (
	"fmt"
	"bufio"
	"os"
	"strings"
)

func main (){
	file, err := os.Open("fin.txt")  //open file
	if err != nil{
		panic(err)
	}
	
	var lines []string	//make arrays for dictionary to be changed/compared and one to be printed
	var ansWords []string
	scanner := bufio.NewScanner(file)
	for scanner.Scan(){
		lines = append(lines, scanner.Text())
		ansWords = append(ansWords, scanner.Text())
	}
	fmt.Println("Enter up to 7 letters")
	var input string
	fmt.Scanln(&input)	//take input
	compareWords(lines, ansWords, input) 
	/*for i, line := range lines {
		fmt.Println(i, line)
	}*/
	
}

func compareWords(lines []string, ansWords []string, inp string)/*([]string)*/{
	inpChars := strings.Split(inp, "")	//make array for input characters 
	for i := 0; i < len(lines); i++{	//iterate through entire dictionary 
		for j := 0; j < len(inpChars); j++{	//iterage through input chars
			if strings.Contains(lines[i], inpChars[j]){	//comapare if dictionary word contains input chars
				lines[i] = strings.Replace(lines[i], inpChars[j], "", 1)  //replace any matching chars w/ ""
			}
		}
		if len(lines[i]) == 0 {
			fmt.Println(ansWords[i]); //print answord of same index if all chars in lines[i] are elim
		}
	}
}

