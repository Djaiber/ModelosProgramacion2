module Ejercicio1 where

--Ejercicio #1:
--Dado un numero n entero calcular la suma de sus digitos

-- Función para calcular la suma de los dígitos de un número entero

sumaDigitos :: Int -> (Int, [Int])
sumaDigitos n = (suma (abs n), digitos (abs n))
  where
    suma 0 = 0
    suma x = (x `mod` 10) + suma (x `div` 10)

    digitos 0 = []
    digitos x = digitos (x `div` 10) ++ [x `mod` 10]


-- Función principal para ejecutar el programa

main :: IO ()
main = do
  putStrLn "Introduce un número entero:"
  input <- getLine
  let numero = read input :: Int  -- Convertimos la entrada a un entero
  let (suma, listaDigitos) = sumaDigitos numero
  putStrLn $ "Los dígitos de " ++ show numero ++ " son: " ++ show listaDigitos
  putStrLn $ "La suma de los dígitos es: " ++ show suma
