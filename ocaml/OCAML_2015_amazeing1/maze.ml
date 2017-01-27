(****************************************************************************)
(*                                                                          *)
(*                     assistants.ml in langage_de_module                   *)
(*                     For Epitech's λ Knowledge Unit                       *)
(*                     Made by: David GIRON                                 *)
(*                                                                          *)
(****************************************************************************)

module type ICASE =
  sig

    type t

    val new_case : bool -> bool -> bool -> int -> int ->int -> int -> t

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


module Case : ICASE =
  struct

    type t = {mutable state : bool; mutable rwall : bool; mutable dwall : bool;
              mutable id : int; mutable x : int; mutable y : int; mutable op : int}

    let new_case s r d i _x _y _op = {state = s; rwall = r; dwall = d; id = i; x = _x; y = _y; op = _op}

    let get_state s = s.state
    let get_rwall s = s.rwall
    let get_dwall s = s.dwall
    let get_id s = s.id
    let get_x s = s.x
    let get_y s = s.y
    let get_open s = s.op

    let set_state s b = s.state <- b
    let set_rwall s r = s.rwall <- r
    let set_dwall s d = s.dwall <- d
    let set_id s id = s.id <- id
    let set_x s x = s.x <- x
    let set_y s y = s.y <- y
    let set_open s op = s.op <- op

  (*   let set_state {state = s; rwall = _; dwall = _; id = _; x = _; y = _} b =
      s <- b
    ;; *)
    let print {state = s; rwall = r; dwall = d; id = i; x = _x; y = _y; op = _op} =
      Printf.printf "%d est un Koala de la promo %d\n" _x _y

  end

