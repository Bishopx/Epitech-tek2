type surname = string;;
type name = string;;
type phone = string;;
type mail = string;;
type nickname = string;;
type birthday = string;;
type age = int;;

type field = All
            | Id
            | Name
            | Surname 
            | Age
            | Email
            | Phone
            | Nickname
            | Birthday
;;

type contact = {
    mutable surname : string;
    mutable name :string;
    mutable age : int;
    mutable email : string;
    mutable phone : string;
    mutable nickname : string;
    mutable birthday : string
};;

module type ICONTACT =
    sig
        val add : contact list -> (surname * name * age * mail * phone * nickname * birthday) -> contact list;;
        val getId : contact list -> field -> string -> int;;
        val remove : contact list -> int -> contact list;;
        val replace : contact list -> int -> (surname * name * age * mail * phone * nickname * birthday) -> contact list;;
        val print : contact list -> field -> string -> unit;;
    end

module Contact : ICONTACT