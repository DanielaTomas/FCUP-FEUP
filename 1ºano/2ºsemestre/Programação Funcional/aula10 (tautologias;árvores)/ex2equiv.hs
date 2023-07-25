import Tautologias

equiv :: Prop -> Prop -> Bool
equiv p q = if tautologia (Conj (Impl p q) (Impl q p)) then True
            else False
