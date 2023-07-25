
module Map (Map,  
            empty, insert, lookup, delete,
            fromList, toList
           ) where
import Prelude hiding (lookup)

data Map k a = Empty
             | Node k a (Map k a) (Map k a)
             deriving Show
                       
empty :: Map k a                       
empty = Empty

insert :: Ord k => k -> a -> Map k a -> Map k a
insert x v Empty = Node x v Empty Empty
insert x v (Node y u l r)
  | x == y = Node x v l r
  | x > y  = Node y u l (insert x v r)
  | x < y  = Node y u (insert x v l) r

lookup :: Ord k => k -> Map k a -> Maybe a
lookup x Empty = Nothing
lookup x (Node y u l r)
  | x == y = Just u
  | x > y  = lookup x r
  | x < y  = lookup x l

delete :: Ord k => k -> Map k a -> Map k a
delete = undefined -- exercício

toList :: Map k a -> [(k,a)]
toList Empty = []
toList (Node x v l r) = toList l ++ [(x,v)] ++ toList r

fromList :: Ord k => [(k,a)] -> Map k a
fromList [] = Empty
fromList ((x,v):rest) = insert x v (fromList rest)
