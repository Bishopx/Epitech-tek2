open Contact
	let database_empty = [];;
let database_alone = [{surname = "Mari prenom"; name = "DUPONT"; age = 52;
email = "m.dupont@familledupont.fr"; phone = "06 12 34 56 78"}];;
let test = Contact.add database_alone ("ChRi-stophe","Plouj",24,"q@s.fr","06 10 91 91 61");;
let test = Contact.add test ("Juju","ThiaWk",22,"julien@gmail.com","07 24 88 88 88");;
let test = Contact.replace test 2 ("Juj","ThiaWk",22,"julien@gmail.com","07 24 88 88 88");;
let test = Contact.remove test 0;;
(* let test = Contact.replace test 3 ("ChRis","Plouj",24,"q@s.fr","06 10 91 91 61");; *)
Contact.print test  Surname "ch";;
print_int (Contact.getId test Surname "u");;