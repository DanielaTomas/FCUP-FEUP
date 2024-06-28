def howmany_within_range2(i, row, minimum, maximum):
   """Returns how many numbers lie within `maximum` and `minimum` in a given `row`"""
   count = 0
   for num in row:
      if minimum <= num <= maximum:
         count = count + 1
 #  print(str(i) + ' ' + count)
   return (i, count)