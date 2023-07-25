{- xor :: Bool -> Bool -> Bool
xor p q = (p || q) && not(p && q)
-}
xor :: Bool -> Bool -> Bool
xor True False  = True
xor False True  = True
xor _ _ = False
