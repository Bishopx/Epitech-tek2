type etudiant = {first_name : string; last_name  :string; promotion : int; is_close : bool};;

let get_first_name etudiant =
	etudiant.first_name
;;

let get_last_name etudiant =
	etudiant.last_name
;;

let get_promotion etudiant =
	etudiant.promotion
;;

let is_close etudiant = 
	etudiant.is_close
;;

let is_in_promo etudiant b = 
	if etudiant.promotion = b then true else false
;;

let rec is_in_promo_range etudiant b c =
	if c < b then false else
	if is_in_promo etudiant c then true else is_in_promo_range etudiant b (c-1)
;;


