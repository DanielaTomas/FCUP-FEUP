module Main where

palavras :: String -> Int
palavras s = length (words s)

linhas :: String -> Int
linhas s = length (lines s)

main :: IO ()
main = do
      txt <- getContents
      print(linhas txt)
      print(palavras txt)
      print(length txt)
