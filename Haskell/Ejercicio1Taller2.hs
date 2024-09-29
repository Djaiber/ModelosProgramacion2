-- Función que transforma un número entero positivo en una cadena de caracteres con los dígitos invertidos
pasarChar :: Int -> String
pasarChar n = reverse (show n)

-- Función principal donde se pide el número al usuario
main :: IO ()
main = do
    putStrLn "Ingresa un número entero positivo:"
    input <- getLine
    let numero = read input :: Int
    putStrLn ("El número " ++ show numero ++ " se transforma en: " ++ pasarChar numero)

