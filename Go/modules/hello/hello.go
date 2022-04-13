package main

import (
	"fmt"
	"github.com/BasilNozdrin/ETU_Basil_N/tree/master/Go/modules/greetings"
)

func main() {
	message := greetings.Hello("Gladys")
	fmt.Println(message)
}
