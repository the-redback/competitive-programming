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
	"math/big"
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

	var tc int
	scanf("%d\n", &tc)

	for t := 0; t < tc; t++ {
		var n, l int
		scanf("%d %d\n", &n, &l)

		a := make([]big.Int, l)
		arr := make([]big.Int, l+1)
		track := make([]big.Int, l+1)
		var i, k int
		var str string
		for i := 0; i < l; i++ {
			scanf("%s ", &str)
			xy, ok := a[i].SetString(str, 10)
			if ok {
				a[i] = *xy
			}

		}
		k = 0
		arr[1] = *arr[1].GCD(nil, nil, &a[0], &a[1])
		track[k] = arr[1]
		k++
		arr[0] = *arr[0].Div(&a[0], &arr[1])
		track[k] = arr[0]
		k++
		for i = 2; i < l; i++ {
			arr[i] = *arr[i].GCD(nil, nil, &a[i-1], &a[i])
			track[k] = arr[i]
			k++
		}
		arr[l] = *arr[l].Div(&a[l-1], &arr[l-1])
		track[k] = arr[l]
		k++

		for i = 0; i < l; i++ {
			for j := 0; j < l-i; j++ {
				if track[j].Cmp(&track[j+1]) > 0 {
					track[j], track[j+1] = track[j+1], track[j]
				}
			}

		}

		mp := make(map[string]int)
		mp[track[0].Text(10)] = 0
		k = 1
		last := track[0]

		for i = 1; i < len(track); i++ {
			if track[i].Cmp(&last) > 0 {
				last = track[i]
				mp[track[i].Text(10)] = k
				k++
			}
		}

		printf("Case #%d: ", t+1)
		for i = 0; i < len(arr); i++ {
			x := mp[arr[i].Text(10)]
			printf("%c", 'A'+x)
		}
		printf("\n")
	}
}
