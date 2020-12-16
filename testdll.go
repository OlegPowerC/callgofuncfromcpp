package main

import "C"
import "fmt"

func main() {

}

//export GoSum
func GoSum(a int,b int) (Gsum int){
	return a+b
}

//export GoAcceptStringParam
func GoAcceptStringParam(a *C.char) (Gsum *C.char){
	GoStr := C.GoString(a)
	ReturnString := fmt.Sprintf("Accepted: %s, len is: %d",GoStr,len(GoStr))
	return C.CString(ReturnString)
}

//export HelloFromGo
func HelloFromGo() (Gsum string){
	return "Hello from Go!"
}
