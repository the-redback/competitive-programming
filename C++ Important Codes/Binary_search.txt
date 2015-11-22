function binarySearch(a, value, left, right)
if right < left
return not found
mid := floor((left+right)/2)
if a[mid] = value
return mid
if value < a[mid]
binarySearch(a, value, left, mid-1)
else
binarySearch(a, value, mid+1, right)