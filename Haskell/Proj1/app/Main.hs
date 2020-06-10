module Main where

import Lib

main :: IO ()
main = interact $ show.sum.map read.words
