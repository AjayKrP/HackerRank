def bin_search(first, last, item):
    if(last >= first):
        middle = (first + last)//2
        if(a[middle] == item):
            return True
        elif(a[middle] > item):
            return bin_search(first, last -1, item)
        elif (a[middle] < item):
            return bin_search(first+1, list, item)
    else:
        return False
