
let get_first_name (prenom, nom, prom, close) = 
	prenom;;

let get_last_name (prenom, nom, prom, close) = 
	nom;;

let get_promotion (prenom, nom, prom, close) = 
	prom;;

let is_close (prenom, nom, prom, close) = 
	close;;

let is_in_promo (prenom, nom, prom, close) b =
	if prom = b then true else false;;

let rec is_in_promo_range (prenom, nom, prom, close) b c =
	if c < b then false else
	if is_in_promo (prenom, nom, prom, close) c then true else is_in_promo_range (prenom, nom, (prom), close) b (c-1)
;;