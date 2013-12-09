Made It!
Made It!
_Stack.Init:
	BeginFunc 8 ;
	EndFunc ;
_Stack.Push:
	BeginFunc 0 ;
	EndFunc ;
_Stack.Pop:
	BeginFunc 8 ;
	_tmp0 = 999 ;
	val = _tmp0 ;
	Return val ;
	EndFunc ;
_Stack.NumElems:
	BeginFunc 0 ;
	EndFunc ;
VTable Stack =
	_Stack.Init,
	_Stack.Push,
	_Stack.Pop,
	_Stack.NumElems,
; 
main:
	BeginFunc 136 ;
	_tmp1 = 12 ;
	PushParam _tmp1 ;
	_tmp2 = LCall _Alloc ;
	PopParams 4 ;
	_tmp3 = Stack ;
	*(_tmp2) = _tmp3 ;
	s = _tmp2 ;
	_tmp4 = *(s) ;
	_tmp5 = *(_tmp4) ;
	PushParam s ;
	ACall _tmp5 ;
	PopParams 4 ;
	_tmp6 = *(s) ;
	_tmp7 = *(_tmp6 + 4) ;
	_tmp8 = 3 ;
	PushParam _tmp8 ;
	PushParam s ;
	ACall _tmp7 ;
	PopParams 8 ;
	_tmp9 = *(s) ;
	_tmp10 = *(_tmp9 + 4) ;
	_tmp11 = 7 ;
	PushParam _tmp11 ;
	PushParam s ;
	ACall _tmp10 ;
	PopParams 8 ;
	_tmp12 = *(s) ;
	_tmp13 = *(_tmp12 + 4) ;
	_tmp14 = 4 ;
	PushParam _tmp14 ;
	PushParam s ;
	ACall _tmp13 ;
	PopParams 8 ;
	_tmp15 = *(s) ;
	_tmp16 = *(_tmp15 + 12) ;
	PushParam s ;
	_tmp17 = ACall _tmp16 ;
	PopParams 4 ;
	PushParam _tmp17 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp18 = " " ;
	PushParam _tmp18 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp19 = *(s) ;
	_tmp20 = *(_tmp19 + 8) ;
	PushParam s ;
	_tmp21 = ACall _tmp20 ;
	PopParams 4 ;
	PushParam _tmp21 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp22 = " " ;
	PushParam _tmp22 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp23 = *(s) ;
	_tmp24 = *(_tmp23 + 8) ;
	PushParam s ;
	_tmp25 = ACall _tmp24 ;
	PopParams 4 ;
	PushParam _tmp25 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp26 = " " ;
	PushParam _tmp26 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp27 = *(s) ;
	_tmp28 = *(_tmp27 + 8) ;
	PushParam s ;
	_tmp29 = ACall _tmp28 ;
	PopParams 4 ;
	PushParam _tmp29 ;
	LCall _PrintInt ;
	PopParams 4 ;
	_tmp30 = " " ;
	PushParam _tmp30 ;
	LCall _PrintString ;
	PopParams 4 ;
	_tmp31 = *(s) ;
	_tmp32 = *(_tmp31 + 12) ;
	PushParam s ;
	_tmp33 = ACall _tmp32 ;
	PopParams 4 ;
	PushParam _tmp33 ;
	LCall _PrintInt ;
	PopParams 4 ;
	EndFunc ;
