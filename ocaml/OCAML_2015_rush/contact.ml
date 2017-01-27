
type surname = string;;
type name = string;;
type phone = string;;
type mail = string;;
type age = int;;

type field = All
     	     | Id
	     | Name
	     | Surname
	     | Age
	     | Email
	     | Phone
;;

type contact = {
    mutable surname : string;
    mutable name :string;
    mutable age : int;
    mutable email : string;
    mutable phone : string
}
;;

exception Add_Contact_With_Invalid_Data;;

exception Remove_Using_An_Invalid_Id;;
exception Remove_Impossible_On_An_Empty_List;;

exception Replace_Impossible_On_An_Empty_List;;
exception Replace_Using_An_Invalid_Id;;
exception Replace_Contact_With_Invalid_Data;;

(* Common func *)

let check_double _surname pos = match _surname.[pos+1] with
	| ' ' -> true
	| _ -> false
;;

let rec remove_blank _surname pos = match String.contains_from _surname pos ' ' with
	| false -> _surname
	| true -> let space_pos = String.index_from _surname pos ' ' in
		match check_double _surname space_pos with
		| false -> remove_blank ((String.sub _surname 0 (space_pos+1))^(String.capitalize (String.trim (String.sub _surname space_pos (String.length _surname - space_pos))))) (space_pos+1)
		| true -> remove_blank ((String.sub _surname 0 (space_pos+1))^(String.capitalize (String.trim (String.sub _surname space_pos (String.length _surname - space_pos))))) (space_pos+1)
;;

let capitalize_surname _surname = match String.contains _surname ' ' with
	| false -> String.capitalize _surname
	| true -> String.capitalize (remove_blank _surname 0)
(* 	String.capitalize _surname *)
;;

let check_surname _surname except = match String.length _surname with
    | 0 -> raise except
    | _ -> capitalize_surname (String.lowercase _surname)
;;

let check_name _name except = match String.length _name with
    | 0 -> raise except
    | _ -> String.uppercase _name
;;

let check_age _age except = match _age with
    | _ when (_age < 0  || _age > 120) -> raise except
    | _ -> _age
;;

let check_mail _mail except = match String.contains _mail '@' with
    | false -> raise except
    | true -> let at_pos = String.index _mail '@' in
    match String.contains_from _mail at_pos '.' with
        | false -> raise except
        | _ when at_pos < 1 -> raise except
        | _ -> let point_pos = String.index _mail '.' in
        match String.length _mail - 1 with
            | _ when String.length _mail - 1 == point_pos -> raise except
            | _ when point_pos < at_pos + 2 -> raise except
            | _ -> _mail
;;

let rec check_phone _phone except i cpt = match String.length _phone - 1 with
    | _ when (i == String.length _phone - 1 && cpt == 9) -> _phone
    | _ when (i == String.length _phone - 1 && cpt != 9) -> raise except
    | _ -> match _phone.[i] with
        | ' ' -> check_phone _phone except (i+1) cpt
        | _  when (_phone.[i] < '0' || _phone.[i] > '9') -> raise except
        | _ -> match cpt with
            | 0 when (_phone.[i] != '0') -> raise except
            | 1 when (_phone.[i] < '1' || _phone.[i] > '9') -> raise except
            | _ -> check_phone _phone except (i+1) (cpt+1)
;;

let strstr a b =
  try
    let len = String.length b in
    for i = 0 to String.length a - len do
      if String.sub a i len = b then raise Exit
    done;
    false
  with Exit -> true
;;

let make_contact (_surname, _name, _age, _mail, _phone) except = 
    {surname =  check_surname (String.trim _surname) except;
                        name = check_name (String.trim _name) except;
                        age = check_age _age except;
                        email = check_mail (String.trim _mail) except; 
                        phone = check_phone (String.trim _phone) except 0 0}
;;

(* ----------------- *)

(* GetId : get list with matching pattern *)

let rec field_all_bool field str = function
    | [] -> false
    | h::t when (strstr (String.lowercase h.surname) (String.lowercase str) && (field == Surname || field == All)) -> true
    | h::t when (strstr (String.lowercase h.name) (String.lowercase str) && (field == Name || field == All)) -> true
    | h::t when (strstr (String.lowercase h.email) (String.lowercase str) && (field == Email || field == All)) -> true
    | h::t when (strstr (String.lowercase h.phone) (String.lowercase str) && (field == Phone || field == All)) -> true
    | h::t when (strstr (string_of_int h.age) str && (field == Age || field == All)) -> true
    | h::t -> field_all_bool field str t
;;

let rec field_all field str i = function
    | [] -> -1
    | h::t when (strstr (String.lowercase h.surname) (String.lowercase str) && 
                (field == Surname || field == All)) && field_all_bool field str t == false -> i
    | h::t when (strstr (String.lowercase h.name) (String.lowercase str) &&
                (field == Name || field == All)) && field_all_bool field str t == false -> i
    | h::t when (strstr (String.lowercase h.email) (String.lowercase str) &&
                (field == Email || field == All)) && field_all_bool field str t == false -> i
    | h::t when (strstr (String.lowercase h.phone) (String.lowercase str) &&
                (field == Phone || field == All)) && field_all_bool field str t == false -> i
    | h::t when (strstr (string_of_int h.age) str &&
                (field == Age || field == All)) && field_all_bool field str t == false -> i
    | h::t -> field_all field str (i+1) t
;;
(* ----------------- *)

(* Print *)
let rec print_space str size_column index = match String.length str + index with
    | _ when (String.length str + index  == size_column) -> ()
    | _ ->
        begin
            print_string " ";
            print_space str size_column (index + 1);
        end
;;

let print_field str size_column = match size_column with
    | _ when size_column > String.length str ->
        begin
            print_string str;
            print_space str size_column 0;
        end
    | _ -> print_string (String.sub str 0 size_column)
;;

let print_one id contact = 
    print_field (string_of_int id) 4;
    print_field contact.surname 16;
    print_field contact.name 16;
    print_field (string_of_int contact.age) 4;
    print_field contact.email 32;
    print_field contact.phone 14;
    print_string "\n"
;;

let get_list_field contact field str = 
    if strstr (String.lowercase contact.surname) (String.lowercase str) && (field == Surname || field == All) then true
    else if strstr (String.lowercase contact.name) (String.lowercase str) && (field == Name || field == All) then true
    else if strstr (String.lowercase contact.email) (String.lowercase str) && (field == Email || field == All) then true 
    else if strstr (String.lowercase contact.phone) (String.lowercase str) && (field == Phone || field == All) then true
    else if strstr (string_of_int contact.age) str && (field == Age || field == All) then true
    else false
;;

let filter_field f contact_list field str =
    let rec helper contact_list a  field str = match contact_list with
        | [] -> List.rev a
        | h::t -> if f h field str then helper t (h::a) field str else helper t a field str
    in helper contact_list [] field str
;;

(* ----------------- *)

(* Replace *)
let rec insert_contact contact n = function
    | [] -> [contact]
    | h::t -> if n = 0 then contact::(h::t) else h::insert_contact contact (n-1) t
;;

(* ----------------- *)

module type ICONTACT =
    sig
        val add : contact list -> (surname * name * age * mail * phone) -> contact list;;
        val getId : contact list -> field -> string -> int;;
        val remove : contact list -> int -> contact list;;
        val replace : contact list -> int -> (surname * name * age * mail * phone) -> contact list;;
        val print : contact list -> field -> string -> unit;;
    end
;;

module Contact : ICONTACT = 
    struct

        let add contact_list (_surname, _name, _age, _mail, _phone) = 
            contact_list@[make_contact (_surname, _name, _age, _mail, _phone) Add_Contact_With_Invalid_Data]
        ;;

        let getId contact_list field str = match field with
            | Id when (int_of_string str < 0 || int_of_string str > List.length contact_list) -> -1
            | Id -> int_of_string str
            | _ -> field_all field str 0 contact_list
        ;;


        let rec remove contact_list id = match contact_list with
            | [] ->  raise Remove_Impossible_On_An_Empty_List
            | h::t when (id == 0) ->  t
            | h::t when (id + 1 > List.length contact_list) -> raise Remove_Using_An_Invalid_Id
            | h::t -> h::remove t (id-1)
        ;;

        let print contact_list field str = match (field, str) with
            | (Id, "") -> ()
            | (Name, "") -> ()
            | (Surname, "") -> ()
            | (Age, "") -> ()
            | (Email, "") -> ()
            | (Phone, "") -> ()
            | (Id, _) -> let contact = List.nth contact_list (int_of_string str) in
                print_one (int_of_string str) contact
            | (_, _) -> let contact = filter_field get_list_field contact_list field str in
                List.iteri print_one contact
        ;;

        let replace contact_list id (_surname, _name, _age, _mail, _phone) = match contact_list with
            | [] -> raise Replace_Impossible_On_An_Empty_List
            | _ when (id + 1 > List.length contact_list) -> raise Replace_Using_An_Invalid_Id
            | _ ->
                let tmp = remove contact_list id and 
                contact = make_contact (_surname, _name, _age, _mail, _phone) Replace_Contact_With_Invalid_Data in
                insert_contact contact id tmp
        ;;

end