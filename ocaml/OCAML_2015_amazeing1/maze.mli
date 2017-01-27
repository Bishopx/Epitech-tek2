(****************************************************************************)
(*                                                                          *)
(*                     maze.mli in langage_de_module                  *)
(*                     For Epitech's λ Knowledge Unit                       *)
(*                     Made by: David GIRON                                 *)
(*                                                                          *)
(****************************************************************************)


module type ICASE =
  sig

    type t

    val new_case : bool -> bool -> bool -> int -> int -> int -> int -> t

    val get_state : t -> bool
    val get_rwall : t -> bool
    val get_dwall : t -> bool
    val get_id : t -> int
    val get_x : t -> int
    val get_y : t -> int
    val get_open : t -> int

    val set_state : t -> bool -> unit
    val set_rwall : t -> bool -> unit
    val set_dwall : t -> bool -> unit
    val set_id : t -> int -> unit
    val set_x : t -> int -> unit
    val set_y : t -> int -> unit
    val set_open : t -> int -> unit
    val print : t -> unit

  end

module Case : ICASE
