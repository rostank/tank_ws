/* ***********************************************************
 * This file was automatically generated on 2020-05-19.      *
 *                                                           *
 * C/C++ Bindings Version 2.1.29                             *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generators git repository on tinkerforge.com       *
 *************************************************************/


#define IPCON_EXPOSE_INTERNALS

#include "bricklet_distance_us.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef void (*Distance_CallbackFunction)(uint16_t distance, void *user_data);

typedef void (*DistanceReached_CallbackFunction)(uint16_t distance, void *user_data);

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#ifdef _WIN32
		// workaround struct packing bug in GCC 4.7 on Windows
		// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=52991
		#define ATTRIBUTE_PACKED __attribute__((gcc_struct, packed))
	#else
		#define ATTRIBUTE_PACKED __attribute__((packed))
	#endif
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDistanceValue_Request;

typedef struct {
	PacketHeader header;
	uint16_t distance;
} ATTRIBUTE_PACKED GetDistanceValue_Response;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetDistanceCallbackPeriod_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDistanceCallbackPeriod_Request;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetDistanceCallbackPeriod_Response;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED SetDistanceCallbackThreshold_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDistanceCallbackThreshold_Request;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED GetDistanceCallbackThreshold_Response;

typedef struct {
	PacketHeader header;
	uint32_t debounce;
} ATTRIBUTE_PACKED SetDebouncePeriod_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDebouncePeriod_Request;

typedef struct {
	PacketHeader header;
	uint32_t debounce;
} ATTRIBUTE_PACKED GetDebouncePeriod_Response;

typedef struct {
	PacketHeader header;
	uint16_t distance;
} ATTRIBUTE_PACKED Distance_Callback;

typedef struct {
	PacketHeader header;
	uint16_t distance;
} ATTRIBUTE_PACKED DistanceReached_Callback;

typedef struct {
	PacketHeader header;
	uint8_t average;
} ATTRIBUTE_PACKED SetMovingAverage_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMovingAverage_Request;

typedef struct {
	PacketHeader header;
	uint8_t average;
} ATTRIBUTE_PACKED GetMovingAverage_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetIdentity_Request;

typedef struct {
	PacketHeader header;
	char uid[8];
	char connected_uid[8];
	char position;
	uint8_t hardware_version[3];
	uint8_t firmware_version[3];
	uint16_t device_identifier;
} ATTRIBUTE_PACKED GetIdentity_Response;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

static void distance_us_callback_wrapper_distance(DevicePrivate *device_p, Packet *packet) {
	Distance_CallbackFunction callback_function;
	void *user_data;
	Distance_Callback *callback;

	if (packet->header.length != sizeof(Distance_Callback)) {
		return; // silently ignoring callback with wrong length
	}

	callback_function = (Distance_CallbackFunction)device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + DISTANCE_US_CALLBACK_DISTANCE];
	user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + DISTANCE_US_CALLBACK_DISTANCE];
	callback = (Distance_Callback *)packet;
	(void)callback; // avoid unused variable warning

	if (callback_function == NULL) {
		return;
	}

	callback->distance = leconvert_uint16_from(callback->distance);

	callback_function(callback->distance, user_data);
}

static void distance_us_callback_wrapper_distance_reached(DevicePrivate *device_p, Packet *packet) {
	DistanceReached_CallbackFunction callback_function;
	void *user_data;
	DistanceReached_Callback *callback;

	if (packet->header.length != sizeof(DistanceReached_Callback)) {
		return; // silently ignoring callback with wrong length
	}

	callback_function = (DistanceReached_CallbackFunction)device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + DISTANCE_US_CALLBACK_DISTANCE_REACHED];
	user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + DISTANCE_US_CALLBACK_DISTANCE_REACHED];
	callback = (DistanceReached_Callback *)packet;
	(void)callback; // avoid unused variable warning

	if (callback_function == NULL) {
		return;
	}

	callback->distance = leconvert_uint16_from(callback->distance);

	callback_function(callback->distance, user_data);
}

void distance_us_create(DistanceUS *distance_us, const char *uid, IPConnection *ipcon) {
	IPConnectionPrivate *ipcon_p = ipcon->p;
	DevicePrivate *device_p;

	device_create(distance_us, uid, ipcon_p, 2, 0, 1, DISTANCE_US_DEVICE_IDENTIFIER);

	device_p = distance_us->p;

	device_p->response_expected[DISTANCE_US_FUNCTION_GET_DISTANCE_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_SET_DISTANCE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_GET_DISTANCE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_SET_DISTANCE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_GET_DISTANCE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_SET_MOVING_AVERAGE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[DISTANCE_US_FUNCTION_GET_MOVING_AVERAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[DISTANCE_US_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	device_p->callback_wrappers[DISTANCE_US_CALLBACK_DISTANCE] = distance_us_callback_wrapper_distance;
	device_p->callback_wrappers[DISTANCE_US_CALLBACK_DISTANCE_REACHED] = distance_us_callback_wrapper_distance_reached;

	ipcon_add_device(ipcon_p, device_p);
}

void distance_us_destroy(DistanceUS *distance_us) {
	device_release(distance_us->p);
}

int distance_us_get_response_expected(DistanceUS *distance_us, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(distance_us->p, function_id, ret_response_expected);
}

int distance_us_set_response_expected(DistanceUS *distance_us, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(distance_us->p, function_id, response_expected);
}

int distance_us_set_response_expected_all(DistanceUS *distance_us, bool response_expected) {
	return device_set_response_expected_all(distance_us->p, response_expected);
}

void distance_us_register_callback(DistanceUS *distance_us, int16_t callback_id, void (*function)(void), void *user_data) {
	device_register_callback(distance_us->p, callback_id, function, user_data);
}

int distance_us_get_api_version(DistanceUS *distance_us, uint8_t ret_api_version[3]) {
	return device_get_api_version(distance_us->p, ret_api_version);
}

int distance_us_get_distance_value(DistanceUS *distance_us, uint16_t *ret_distance) {
	DevicePrivate *device_p = distance_us->p;
	GetDistanceValue_Request request;
	GetDistanceValue_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_GET_DISTANCE_VALUE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_distance = leconvert_uint16_from(response.distance);

	return ret;
}

int distance_us_set_distance_callback_period(DistanceUS *distance_us, uint32_t period) {
	DevicePrivate *device_p = distance_us->p;
	SetDistanceCallbackPeriod_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_SET_DISTANCE_CALLBACK_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int distance_us_get_distance_callback_period(DistanceUS *distance_us, uint32_t *ret_period) {
	DevicePrivate *device_p = distance_us->p;
	GetDistanceCallbackPeriod_Request request;
	GetDistanceCallbackPeriod_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_GET_DISTANCE_CALLBACK_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_period = leconvert_uint32_from(response.period);

	return ret;
}

int distance_us_set_distance_callback_threshold(DistanceUS *distance_us, char option, uint16_t min, uint16_t max) {
	DevicePrivate *device_p = distance_us->p;
	SetDistanceCallbackThreshold_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_SET_DISTANCE_CALLBACK_THRESHOLD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_uint16_to(min);
	request.max = leconvert_uint16_to(max);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int distance_us_get_distance_callback_threshold(DistanceUS *distance_us, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	DevicePrivate *device_p = distance_us->p;
	GetDistanceCallbackThreshold_Request request;
	GetDistanceCallbackThreshold_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_GET_DISTANCE_CALLBACK_THRESHOLD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_option = response.option;
	*ret_min = leconvert_uint16_from(response.min);
	*ret_max = leconvert_uint16_from(response.max);

	return ret;
}

int distance_us_set_debounce_period(DistanceUS *distance_us, uint32_t debounce) {
	DevicePrivate *device_p = distance_us->p;
	SetDebouncePeriod_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_SET_DEBOUNCE_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int distance_us_get_debounce_period(DistanceUS *distance_us, uint32_t *ret_debounce) {
	DevicePrivate *device_p = distance_us->p;
	GetDebouncePeriod_Request request;
	GetDebouncePeriod_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_GET_DEBOUNCE_PERIOD, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_debounce = leconvert_uint32_from(response.debounce);

	return ret;
}

int distance_us_set_moving_average(DistanceUS *distance_us, uint8_t average) {
	DevicePrivate *device_p = distance_us->p;
	SetMovingAverage_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_SET_MOVING_AVERAGE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.average = average;

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int distance_us_get_moving_average(DistanceUS *distance_us, uint8_t *ret_average) {
	DevicePrivate *device_p = distance_us->p;
	GetMovingAverage_Request request;
	GetMovingAverage_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_GET_MOVING_AVERAGE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_average = response.average;

	return ret;
}

int distance_us_get_identity(DistanceUS *distance_us, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	DevicePrivate *device_p = distance_us->p;
	GetIdentity_Request request;
	GetIdentity_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_US_FUNCTION_GET_IDENTITY, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	memcpy(ret_uid, response.uid, 8);
	memcpy(ret_connected_uid, response.connected_uid, 8);
	*ret_position = response.position;
	memcpy(ret_hardware_version, response.hardware_version, 3 * sizeof(uint8_t));
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	*ret_device_identifier = leconvert_uint16_from(response.device_identifier);

	return ret;
}

#ifdef __cplusplus
}
#endif
