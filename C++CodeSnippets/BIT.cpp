/*
1 base indexing

(I) Point Update, Range Query:
    Add v at point x : update(x,v)
    Sum[a,b] = query(b) - query(a-1)

(II) Range Update, Point Query:
     Add v at range [a,b] : update(a,v), update(b+1,-v)
     Value at point x = query(X)

(III) Range Update, Range Query:
      We have to use 2 BIT
      Add v at range [a,b] : update(a,v), update(b+1,-v), update2(a,v*(a-1)), update2(b+1,-v*b)
      Sum[0,x] = x*query(x) - query2(x)
      Sum[a,b] = Sum[0,b] - Sum[0,a-1]
*/
