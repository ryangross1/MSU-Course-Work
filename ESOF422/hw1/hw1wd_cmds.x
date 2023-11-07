!create p1:Player
!create w:Weapon
!create wt:Sword
!create wd:WeaponDecorator
!create b:Blade
!create g:Grip
!create h:Handle
!create p:Pommel
!set p1.name := 'Cheeseman'
!set w.weaponName := 'Silver Sword'
!set wt.weight := 5
!set wt.reach := 5
!set b.type := 'Silver'
!set g.type := 'Leather'
!set p.type := 'Spike'
!set h.type := 'Oak'
!insert (p1,w) into heldWeapon
!insert (w, wt) into weaponType2
!insert (wd, b, h, g, p) into weaponPart
!w.getWeaponName()