package main
import "fmt"

var str string = ""
var lstr[] string

func Combination(digits string) {
	if(len(digits)==0){
		lstr = append(lstr,str)
		return
	}
	if(digits[0] >= '2' && digits[0] <= '9'){
		count := 3
		start := 0
		if digits[0] == '7'{
			count++
		} else if digits[0] == '8'{
			start++
			count++
		} else if digits[0] == '9'{
			start++
			count += 2
		}
		sz := len(str)
		for i := start; i < count; i++ {
			str += string(int('A' + ((digits[0] -'2')*3)) + i)
			Combination(digits[1:])
			str = str[:sz]
		}
	}
}

func LetterCombination(digits string)[]string{
	lstr = nil
	if len(digits) > 0{
		Combination(digits)
	} 
	return lstr
}

func main(){
	LetterCombination("23")
	fmt.Println(lstr)
	LetterCombination("564")
	fmt.Println(lstr)
	LetterCombination("5664")
	fmt.Println(lstr)
	LetterCombination("78")
	fmt.Println(lstr)
	LetterCombination("952")
	fmt.Println(lstr)
	LetterCombination("27")
	fmt.Println(lstr)
	LetterCombination("8")
	fmt.Println(lstr)
	LetterCombination("995")
	fmt.Println(lstr)
}
