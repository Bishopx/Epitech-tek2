exception FoundZero;;
let rec list_mul_without liste = match liste with
	| [] -> 1
	| 0 :: _ -> raise FoundZero
	| tete::reste -> tete * list_mul_without reste
;;

let list_mul l =
	try list_mul_without l with FoundZero -> 0;;		