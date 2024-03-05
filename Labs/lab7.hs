circle :: String -> Double -> Double
circle action radius
 | action == "circumference" = 2 * pi * radius
 | action == "area" = pi * radius^2
 | otherwise = 0.0

cylinder :: String -> Double -> Double -> Double
cylinder action radius height
 | action == "volume" = (circle "area" radius) * height
 | action == "area" = 2 * (circle "area" radius) + (circle "circumference" radius) * height
 | otherwise = 0.0

gCD :: Integer -> Integer -> Integer
gCD a b
 | b == 0 = a
 | otherwise = gCD b (a `mod` b)

isDivisible :: Integer -> Integer -> Bool
isDivisible x y = x `mod` y == 0

highway :: Int -> String
highway number
    | number < 1 || number > 999 = "Not a valid interstate highway number"
    | number < 100 = "Primary interstate highway number"
    | isDivisible (toInteger number) 100 = "Not a valid interstate highway number"
    | otherwise = "Auxiliary interstate highway, serving I-" ++ show (number `mod` 100)