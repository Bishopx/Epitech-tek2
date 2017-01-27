type 'a my_list = Item of ('a * 'a my_list) | Empty

(* let exemple = Item ("test", Item("test1", Empty));;
let ingredients = Item ("farine", Item ("beurre", Item ("lait" , Item ("sucre", Empty))));;
let inte = Item (("sucre", 12), Item (("exe", 22), Item(("exe", 23), Empty)));;
let item = Item (Item(1, Item(2, Empty)), Empty);;
let exe = Item(100, Item(2, Item(31, Item(21, Empty))));; *)
(* let somme a = a + 2;; *)

let rec iter func liste = match liste with
 	| Empty -> ()
	| Item (hd, tl) ->
		begin
			func hd;
			iter func tl
 		end
;;

let rec length liste = match liste with
	| Empty -> 0
	| Item (hd,tl) -> 1 + length tl
;;

let rec hd liste = match liste with
	| Empty -> raise (Failure "hd")
	| Item (hd, tl) -> hd;
;;

let rec tl liste = match liste with
	| Empty -> raise (Failure "tl")
	| Item (hd, tl) -> tl
;;

let rec nth liste n = match liste, n with
	| Empty, _ -> raise (Failure "nth")
	| _, n when n < 0 -> raise (Invalid_argument "List.nth")
	| Item (hd, tl), 0 -> hd
	| Item (hd, tl), n -> nth tl (n - 1)
;;

let rev l =
  let rec helper l a = match l with
    | Empty -> a
    | Item (hd, tl) -> helper tl (Item (hd, a))
  in 
  helper l Empty
;;

let rec append l1 l2 = match l1 with
	| Empty -> l2
	| Item (hd, tl) -> Item (hd, append tl l2)
;;

let rec flatten l = match l with
	| Empty -> Empty
	| Item(hd, tl) -> append hd (flatten tl) 
;;

let rec rev_append l1 l2 = append (rev l1) l2
;;

let rec for_all func l1 = match l1 with
	| Empty -> true
	| Item (hd, tl) -> func hd && for_all func tl
;;

let rec exists func l1 = match l1 with
	| Empty -> false
	| Item (hd, tl) -> func hd || exists func tl
;;

let rec mem a l = match l with
	| Empty -> false
	| Item(hd, tl) -> if hd = a then true else mem a tl
;;

let rec memq a l = match l with
	| Empty -> false
	| Item(hd, tl) -> if hd == a then true else memq a tl
;;

let rec map f l = match l with
	| Empty -> Empty
	| Item(hd, tl) -> Item((f hd), (map f tl))
;;

let rec fold_left f a l= match l with
    | Empty -> a
  	| Item(hd, tl) -> fold_left f (f a hd) tl
;;

let filter f l =
	let rec helper l a = match l with
		| Empty -> rev a
		| Item(hd, tl) -> if f hd then helper tl (Item(hd, a)) else helper tl a
	in helper l Empty
;;

let rec mem_assoc k l = match l with
	| Empty -> false
	| Item((a, b), tl) -> if k = a then true else mem_assoc k tl 
;;

let rec assoc k l = match l with
	| Empty -> raise Not_found
	| Item((a, b), tl) -> if k = a then b else assoc k tl		
;;

let rec split l = match l with
	| Empty -> (Empty, Empty)
	| Item((a, b), tl) -> let (x, y) = split tl
		in (Item(a, x), Item(b, y))
;;

let rec remove_assoc k l = match l with
	| Empty -> Empty
	| Item((a, b), tl) -> if k = a then tl else (Item((a, b), (remove_assoc k tl)))
;;

let rec iter2 func l1 l2 = match (l1, l2) with
	| (Empty, Empty) -> ()
	| (Item (h1, t1), Item(h2, t2)) ->
		begin
			func h1 h2;
			iter2 func t1 t2;
		end
	| (_, _) -> raise (Invalid_argument "List.iter2")
;;

