scanll' :: (b -> a -> b) -> b -> [a] -> [b]
scanll' _ ac [] = [ac]
scanll' f ac (x:xs) = (f ac x) : scanll f (f ac x) xs

scanll f ac l = ac : sacanll' f ac l
