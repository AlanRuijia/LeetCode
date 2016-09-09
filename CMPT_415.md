###CMPT 415

####Grade

* 10% participation
* 20% midterm (Oct. 25) 2 hours
* 30% final (Dec. 14)
* 40% assignments 4 out of 5 every 2 weeks
----

####Contact

* TA Saman samaut@sfu.ca
* Canvas
* Wed. 2-3 Fri. 1-2 TASC1 8000
* Professor Leonid Thu. 12:30-1:30 TASC1 9425 
----

#### Ground rules

----

#### Pseudocode

* template:

		Input: an array S, assume is sorted; value v to find
		Output: location of v in S, or 0 if v not in S
		Algorithm:
			low := 1, high := S.size(), loc := 0
			while (loc <= high and loc = 0){
				mid := floor((low + high)/2) 
				if (S[mid] = v)
					return mid
				else if (S[mid] > v)
					high := mid - 1
				else 
					low := mid + 1 
				if (low > high)
					return 0
			}

			BinSearch(S, v, low, high){
				if (low > high)
					return 0
				else {
					mid = floor((low + high)/2)
					if (S[mid] = v)
						return mid
					else if (S[mid] > v)
						return BinSearch(S, v, low, mid-1)
					else 
						return BinSearch(S, v, mid+1, high)
				}
			}


#### Syllabus

* Greedy Algorithms
* Dynamic Programming
* Graph Algorithms
* Linear Programming 
* Models of computation
* Computational complexity
* Approximation algorithms


### Greedy Algorithms

* solve optimization problems by taking the single "most valuable option" ate every step. Minimize cost or Maximaze profit.

* Change-making problem:
	* Given denominations: d1 < d2 < ... < dk and an amount n
	* Find the smallest number of coins t such that n = sum(d_im) m = 1 to t for some indice im
	1 5 10 25 100 200
