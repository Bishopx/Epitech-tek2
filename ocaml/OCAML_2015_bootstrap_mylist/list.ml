let rec iter func liste = match liste with
 	| [] -> []
	| tete::reste ->
		begin
			func tete;
			iter func reste
 		end
;;

(* let rec size liste = match liste with
	| [] -> 0
	| tete::reste -> 1 + size reste;;

let rec drop_value l to_drop =
    match l with
    | [] -> []
    | hd :: tl ->
      let new_tl = drop_value tl to_drop in
      if hd = to_drop then new_tl else hd :: new_tl
  ;;

type 'a my_list = Item of ('a * 'a my_list) | Empty *)

