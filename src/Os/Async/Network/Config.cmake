cmake_minimum_required(VERSION 3.14)

function(lib_generate_network_config)
	flame_generate_config(
		FILE "${CMAKE_CURRENT_LIST_DIR}/Config.hpp.in"
		OUTPUT "${GENERATION_INLCUDE_PATH}/Generated/Network/Config.hpp"
		PARAMETERS
			# UDP
			"LIB_UDP_SERVERS" "8"
			"LIB_UDP_SERVER_INPUT_QUEUE_SIZE" "32"
			"LIB_UDP_SERVER_OUTPUT_QUEUE_SIZE" "32"
			"LIB_UDP_CLIENTS" "16"
			"LIB_UDP_CLIENT_INPUT_QUEUE_SIZE" "32"
			"LIB_UDP_CLIENT_OUTPUT_QUEUE_SIZE" "32"
			"LIB_UDP_MESSAGE_SIZE" "32 * 1024"
			# TCP
			"LIB_TCP_SERVERS" "8"
			"LIB_TCP_SERVER_BACKLOG" "1024"
			"LIB_TCP_SERVER_INPUT_BUFFER_SIZE" "64 * 1024"
			"LIB_TCP_SERVER_OUTPUT_BUFFER_SIZE" "64 * 1024"
			"LIB_TCP_CLIENTS" "16"
			"LIB_TCP_CLIENT_INPUT_BUFFER_SIZE" "64 * 1024"
			"LIB_TCP_CLIENT_OUTPUT_BUFFER_SIZE" "64 * 1024"
			# Common
			"LIB_HANDLER_NUMBER_OF_WORKERS" "2"
	)
endfunction()
lib_generate_network_config()
