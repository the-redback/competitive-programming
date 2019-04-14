/***
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://maruftuhin.com
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

// Debug micro. Starts
var DEBUG = "N"
var DEBUG_BOOL = false

func debug(args ...interface{}) {
	if DEBUG_BOOL {
		fmt.Fprintln(os.Stderr, args...)
	}
}

// Ends

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	if DEBUG != "N" {
		DEBUG_BOOL = true
	}

	// STDOUT MUST BE FLUSHED MANUALLY!!!
	defer writer.Flush()
	var a, b int
	scanf("%d %d\n", &a, &b)

	// Code here!!!

	printf("%d\n", a+b)
}
