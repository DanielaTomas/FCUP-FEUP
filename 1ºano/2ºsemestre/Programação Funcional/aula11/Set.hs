module Set (Set,
            empty, isEmpty, insert, delete, member,
            fromList, toList, union, intersection) where

data Set a = Empty
           | Node a (Set a) (Set a)
           deriving Show

empty :: Set a
empty = Empty

isEmpty :: Set a -> Bool
isEmpty Empty = True
isEmpty _     = False

fromList :: Ord a => [a] -> Set a
fromList xs = foldr insert Empty xs

toList :: Set a -> [a]
toList Empty = []
toList (Node x l r) = toList l ++ [x] ++ toList r


member :: Ord a => a -> Set a -> Bool
member x Empty = False
member x (Node y l r)
  | x == y = True
  | x > y  = member x r
  | x < y  = member x l

insert :: Ord a => a -> Set a -> Set a
insert x Empty = Node x Empty Empty
insert x (Node y l r)
  | x == y = Node y l r
  | x > y  = Node y l (insert x r)
  | x < y  = Node y (insert x l) r


delete :: Ord a => a -> Set a -> Set a
delete = undefined -- exercício

union :: Ord a => Set a -> Set a -> Set a
union = undefined  -- exercício 

intersection :: Ord a => Set a -> Set a -> Set a
intersection = undefined -- exercício
