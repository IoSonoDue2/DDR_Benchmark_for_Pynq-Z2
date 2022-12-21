set SynModuleInfo {
  {SRCNAME ddrbenchmark2_Pipeline_access MODELNAME ddrbenchmark2_Pipeline_access RTLNAME ddrbenchmark2_ddrbenchmark2_Pipeline_access
    SUBMODULES {
      {MODELNAME ddrbenchmark2_flow_control_loop_pipe_sequential_init RTLNAME ddrbenchmark2_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME ddrbenchmark2_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME ddrbenchmark2 MODELNAME ddrbenchmark2 RTLNAME ddrbenchmark2 IS_TOP 1
    SUBMODULES {
      {MODELNAME ddrbenchmark2_gmem_m_axi RTLNAME ddrbenchmark2_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME ddrbenchmark2_control_s_axi RTLNAME ddrbenchmark2_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
