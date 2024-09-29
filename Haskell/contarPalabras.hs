-- Función para contar la cantidad de palabras en un texto
contarPalabras :: String -> Int
contarPalabras texto = length (words texto)

-- Función principal donde se pide el texto al usuario
main :: IO ()
main = do
    putStrLn "Ingresa un texto corto:"
    texto <- getLine
    let cantidadPalabras = contarPalabras texto
    putStrLn ("El texto contiene " ++ show cantidadPalabras ++ " palabras.")
