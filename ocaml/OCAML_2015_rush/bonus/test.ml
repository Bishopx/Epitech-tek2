open Contact

let database_empty = [];;
let database_alone = [{surname = "Mariju"; name = "DUPONT"; age = 52;
email = "m.dupont@familledupont.fr"; phone = "06 12 34 56 78"; nickname = "marie_d"; birthday = "21/12/1942"}];;
let test = Contact.add database_alone ("ChRis","Plouj",24,"q@s.fr","06 10 91 91 61", "ploujo_c", "06/09/1991");;
let test = Contact.add test ("Juju","ThiaWk",22,"julien@gmail.com","  07 24 88 88 88", "thiawk_j", "30/10/1994");;
(* let test = Contact.replace test 2 ("ChRis","Plouj",24,"q@s.fr","06 10 91 91 61", "ploujo", "06/05/1991");; *)
Contact.print test  All "";;
