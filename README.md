# Spiral Matrix
----
## What is the spiral matrix?
The maxtrix is filled in a sprial way like below.

	0	1	2	3	4
	15	16	17	18	5
	14	23	24	19	6
	13	22	21	20	7
	12	11	10	9	8

If there is a block,the filling direction is changed in the clockwise direction.

## Usage

### Input
| input | meaning    					|
| ----- | -------    					|
| 5 5   |matrix size(row,col)			|
| 2     |block number					|
| 3 3   |the first block position(x,y)	|
| 2 2 	|the second block position(x,y) |

### Result
	-	-	-	-	-
	-	-	-	-	-
	-	-	x	-	-
	-	-	-	x	-
	-	-	-	-	-
	0	1	2	3	4
	15	16	17	18	5
	14	-	x	19	6
	13	-	-	x	7
	12	11	10	9	8

