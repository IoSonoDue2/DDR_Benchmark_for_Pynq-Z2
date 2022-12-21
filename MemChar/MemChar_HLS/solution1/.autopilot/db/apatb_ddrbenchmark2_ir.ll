; ModuleID = '/home/due2/Desktop/FPGAs/MemChar/MemChar_HLS/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

%"struct.ap_uint<64>" = type { %"struct.ap_int_base<64, false>" }
%"struct.ap_int_base<64, false>" = type { %"struct.ssdm_int<64, false>" }
%"struct.ssdm_int<64, false>" = type { i64 }

; Function Attrs: noinline
define void @apatb_ddrbenchmark2_ir(%"struct.ap_uint<64>"* noalias nocapture nonnull readonly %input, %"struct.ap_uint<64>"* noalias nocapture nonnull %output) local_unnamed_addr #0 {
entry:
  %malloccall = call i8* @malloc(i64 8000)
  %input_copy = bitcast i8* %malloccall to [1000 x i64]*
  %malloccall1 = call i8* @malloc(i64 8000)
  %output_copy = bitcast i8* %malloccall1 to [1000 x i64]*
  %0 = bitcast %"struct.ap_uint<64>"* %input to [1000 x %"struct.ap_uint<64>"]*
  %1 = bitcast %"struct.ap_uint<64>"* %output to [1000 x %"struct.ap_uint<64>"]*
  call fastcc void @copy_in([1000 x %"struct.ap_uint<64>"]* nonnull %0, [1000 x i64]* %input_copy, [1000 x %"struct.ap_uint<64>"]* nonnull %1, [1000 x i64]* %output_copy)
  %2 = getelementptr [1000 x i64], [1000 x i64]* %input_copy, i32 0, i32 0
  %3 = getelementptr [1000 x i64], [1000 x i64]* %output_copy, i32 0, i32 0
  call void @apatb_ddrbenchmark2_hw(i64* %2, i64* %3)
  call void @copy_back([1000 x %"struct.ap_uint<64>"]* %0, [1000 x i64]* %input_copy, [1000 x %"struct.ap_uint<64>"]* %1, [1000 x i64]* %output_copy)
  call void @free(i8* %malloccall)
  call void @free(i8* %malloccall1)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_in([1000 x %"struct.ap_uint<64>"]* noalias readonly, [1000 x i64]* noalias, [1000 x %"struct.ap_uint<64>"]* noalias readonly, [1000 x i64]* noalias) unnamed_addr #1 {
entry:
  call fastcc void @"onebyonecpy_hls.p0a1000struct.ap_uint<64>.9"([1000 x i64]* %1, [1000 x %"struct.ap_uint<64>"]* %0)
  call fastcc void @"onebyonecpy_hls.p0a1000struct.ap_uint<64>.9"([1000 x i64]* %3, [1000 x %"struct.ap_uint<64>"]* %2)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_out([1000 x %"struct.ap_uint<64>"]* noalias, [1000 x i64]* noalias readonly, [1000 x %"struct.ap_uint<64>"]* noalias, [1000 x i64]* noalias readonly) unnamed_addr #2 {
entry:
  call fastcc void @"onebyonecpy_hls.p0a1000struct.ap_uint<64>"([1000 x %"struct.ap_uint<64>"]* %0, [1000 x i64]* %1)
  call fastcc void @"onebyonecpy_hls.p0a1000struct.ap_uint<64>"([1000 x %"struct.ap_uint<64>"]* %2, [1000 x i64]* %3)
  ret void
}

declare void @free(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0a1000struct.ap_uint<64>"([1000 x %"struct.ap_uint<64>"]* noalias, [1000 x i64]* noalias readonly) unnamed_addr #3 {
entry:
  %2 = icmp eq [1000 x %"struct.ap_uint<64>"]* %0, null
  %3 = icmp eq [1000 x i64]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx7 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %5 = getelementptr [1000 x i64], [1000 x i64]* %1, i64 0, i64 %for.loop.idx7
  %dst.addr.0.0.06 = getelementptr [1000 x %"struct.ap_uint<64>"], [1000 x %"struct.ap_uint<64>"]* %0, i64 0, i64 %for.loop.idx7, i32 0, i32 0, i32 0
  %6 = load i64, i64* %5, align 8
  store i64 %6, i64* %dst.addr.0.0.06, align 8
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx7, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 1000
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @"onebyonecpy_hls.p0a1000struct.ap_uint<64>.9"([1000 x i64]* noalias, [1000 x %"struct.ap_uint<64>"]* noalias readonly) unnamed_addr #3 {
entry:
  %2 = icmp eq [1000 x i64]* %0, null
  %3 = icmp eq [1000 x %"struct.ap_uint<64>"]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx7 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %src.addr.0.0.05 = getelementptr [1000 x %"struct.ap_uint<64>"], [1000 x %"struct.ap_uint<64>"]* %1, i64 0, i64 %for.loop.idx7, i32 0, i32 0, i32 0
  %5 = getelementptr [1000 x i64], [1000 x i64]* %0, i64 0, i64 %for.loop.idx7
  %6 = load i64, i64* %src.addr.0.0.05, align 8
  store i64 %6, i64* %5, align 8
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx7, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 1000
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

declare void @apatb_ddrbenchmark2_hw(i64*, i64*)

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @copy_back([1000 x %"struct.ap_uint<64>"]* noalias, [1000 x i64]* noalias readonly, [1000 x %"struct.ap_uint<64>"]* noalias, [1000 x i64]* noalias readonly) unnamed_addr #2 {
entry:
  call fastcc void @"onebyonecpy_hls.p0a1000struct.ap_uint<64>"([1000 x %"struct.ap_uint<64>"]* %2, [1000 x i64]* %3)
  ret void
}

define void @ddrbenchmark2_hw_stub_wrapper(i64*, i64*) #4 {
entry:
  %malloccall = tail call i8* @malloc(i64 8000)
  %2 = bitcast i8* %malloccall to [1000 x %"struct.ap_uint<64>"]*
  %malloccall1 = tail call i8* @malloc(i64 8000)
  %3 = bitcast i8* %malloccall1 to [1000 x %"struct.ap_uint<64>"]*
  %4 = bitcast i64* %0 to [1000 x i64]*
  %5 = bitcast i64* %1 to [1000 x i64]*
  call void @copy_out([1000 x %"struct.ap_uint<64>"]* %2, [1000 x i64]* %4, [1000 x %"struct.ap_uint<64>"]* %3, [1000 x i64]* %5)
  %6 = bitcast [1000 x %"struct.ap_uint<64>"]* %2 to %"struct.ap_uint<64>"*
  %7 = bitcast [1000 x %"struct.ap_uint<64>"]* %3 to %"struct.ap_uint<64>"*
  call void @ddrbenchmark2_hw_stub(%"struct.ap_uint<64>"* %6, %"struct.ap_uint<64>"* %7)
  call void @copy_in([1000 x %"struct.ap_uint<64>"]* %2, [1000 x i64]* %4, [1000 x %"struct.ap_uint<64>"]* %3, [1000 x i64]* %5)
  ret void
}

declare void @ddrbenchmark2_hw_stub(%"struct.ap_uint<64>"*, %"struct.ap_uint<64>"*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #4 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
