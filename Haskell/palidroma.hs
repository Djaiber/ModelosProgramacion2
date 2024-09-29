-- Función para verificar si una palabra es palíndromo
esPalindromo :: String -> Bool
esPalindromo [] = True
esPalindromo [_] = True
esPalindromo (x:xs) = x == last xs && esPalindromo (init xs)

-- Función para convertir una palabra en palíndromo en el menor número de pasos
convertirAPalindromo :: String -> String
convertirAPalindromo [] = []
convertirAPalindromo [x] = [x]
convertirAPalindromo (x:xs)
  | x == last xs = x : convertirAPalindromo (init xs) ++ [x]
  | otherwise = x : convertirAPalindromo (init xs) ++
