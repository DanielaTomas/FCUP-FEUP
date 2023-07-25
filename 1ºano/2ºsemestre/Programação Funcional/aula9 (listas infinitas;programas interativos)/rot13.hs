module Main where
import Data.Char

rot13 :: Int -> String -> String
rot13 n = map f
          where f x | not (isLetter x) = x
                    | isUpper x = rot13Upper n x
                    | otherwise = rot13Lower n x

rot13Upper :: Int -> Char -> Char
rot13Upper n x | chr ((ord x) + n) < 'A' || chr ((ord x) + n) > 'Z' = upperAux (n-1) x
               | otherwise = chr ((ord x) + n)

upperAux :: Int -> Char -> Char
upperAux n x | chr (abs((ord x) + n)) < 'A' || chr (abs((ord x) + n)) > 'Z' = upperAux (n-1) x
             | otherwise = chr ((ord 'A') + (13-n-1))

rot13Lower :: Int -> Char -> Char
rot13Lower n x | chr ((ord x) + n) < 'a' || chr ((ord x) + n) > 'z' = upperAux (n-1) x
               | otherwise = chr ((ord x) + n)

lowerAux :: Int -> Char -> Char
lowerAux n x | chr (abs((ord x) + n)) < 'a' || chr (abs((ord x) + n)) > 'z' = lowerAux (n-1) x
             | otherwise = chr ((ord 'a') + (13-n-1))

main :: IO()
main = do
        x <- getContents
        putStrLn(rot13 13 x)
