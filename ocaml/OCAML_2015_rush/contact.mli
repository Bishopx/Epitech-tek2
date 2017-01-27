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
};;

module type ICONTACT =
	sig
		val add : contact list -> (surname * name * age * mail * phone) -> contact list;;
		val getId : contact list -> field -> string -> int;;
		val remove : contact list -> int -> contact list;;
		val replace : contact list -> int -> (surname * name * age * mail * phone) -> contact list;;
		val print : contact list -> field -> string -> unit;;
	end

module Contact : ICONTACT