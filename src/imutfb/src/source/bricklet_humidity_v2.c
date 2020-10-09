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

#include "bricklet_humidity_v2.h"

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif



typedef void (*Humidity_CallbackFunction)(uint16_t humidity, void *user_data);

typedef void (*Temperature_CallbackFunction)(int16_t temperature, void *user_data);

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
} ATTRIBUTE_PACKED GetHumidity_Request;

typedef struct {
	PacketHeader header;
	uint16_t humidity;
} ATTRIBUTE_PACKED GetHumidity_Response;

typedef struct {
	PacketHeader header;
	uint32_t period;
	uint8_t value_has_to_change;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED SetHumidityCallbackConfiguration_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetHumidityCallbackConfiguration_Request;

typedef struct {
	PacketHeader header;
	uint32_t period;
	uint8_t value_has_to_change;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED GetHumidityCallbackConfiguration_Response;

typedef struct {
	PacketHeader header;
	uint16_t humidity;
} ATTRIBUTE_PACKED Humidity_Callback;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetTemperature_Request;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED GetTemperature_Response;

typedef struct {
	PacketHeader header;
	uint32_t period;
	uint8_t value_has_to_change;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED SetTemperatureCallbackConfiguration_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetTemperatureCallbackConfiguration_Request;

typedef struct {
	PacketHeader header;
	uint32_t period;
	uint8_t value_has_to_change;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetTemperatureCallbackConfiguration_Response;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED Temperature_Callback;

typedef struct {
	PacketHeader header;
	uint8_t heater_config;
} ATTRIBUTE_PACKED SetHeaterConfiguration_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetHeaterConfiguration_Request;

typedef struct {
	PacketHeader header;
	uint8_t heater_config;
} ATTRIBUTE_PACKED GetHeaterConfiguration_Response;

typedef struct {
	PacketHeader header;
	uint16_t moving_average_length_humidity;
	uint16_t moving_average_length_temperature;
} ATTRIBUTE_PACKED SetMovingAverageConfiguration_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMovingAverageConfiguration_Request;

typedef struct {
	PacketHeader header;
	uint16_t moving_average_length_humidity;
	uint16_t moving_average_length_temperature;
} ATTRIBUTE_PACKED GetMovingAverageConfiguration_Response;

typedef struct {
	PacketHeader header;
	uint8_t sps;
} ATTRIBUTE_PACKED SetSamplesPerSecond_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetSamplesPerSecond_Request;

typedef struct {
	PacketHeader header;
	uint8_t sps;
} ATTRIBUTE_PACKED GetSamplesPerSecond_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetSPITFPErrorCount_Request;

typedef struct {
	PacketHeader header;
	uint32_t error_count_ack_checksum;
	uint32_t error_count_message_checksum;
	uint32_t error_count_frame;
	uint32_t error_count_overflow;
} ATTRIBUTE_PACKED GetSPITFPErrorCount_Response;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED SetBootloaderMode_Request;

typedef struct {
	PacketHeader header;
	uint8_t status;
} ATTRIBUTE_PACKED SetBootloaderMode_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetBootloaderMode_Request;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED GetBootloaderMode_Response;

typedef struct {
	PacketHeader header;
	uint32_t pointer;
} ATTRIBUTE_PACKED SetWriteFirmwarePointer_Request;

typedef struct {
	PacketHeader header;
	uint8_t data[64];
} ATTRIBUTE_PACKED WriteFirmware_Request;

typedef struct {
	PacketHeader header;
	uint8_t status;
} ATTRIBUTE_PACKED WriteFirmware_Response;

typedef struct {
	PacketHeader header;
	uint8_t config;
} ATTRIBUTE_PACKED SetStatusLEDConfig_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetStatusLEDConfig_Request;

typedef struct {
	PacketHeader header;
	uint8_t config;
} ATTRIBUTE_PACKED GetStatusLEDConfig_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetChipTemperature_Request;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED GetChipTemperature_Response;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Reset_Request;

typedef struct {
	PacketHeader header;
	uint32_t uid;
} ATTRIBUTE_PACKED WriteUID_Request;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED ReadUID_Request;

typedef struct {
	PacketHeader header;
	uint32_t uid;
} ATTRIBUTE_PACKED ReadUID_Response;

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

static void humidity_v2_callback_wrapper_humidity(DevicePrivate *device_p, Packet *packet) {
	Humidity_CallbackFunction callback_function;
	void *user_data;
	Humidity_Callback *callback;

	if (packet->header.length != sizeof(Humidity_Callback)) {
		return; // silently ignoring callback with wrong length
	}

	callback_function = (Humidity_CallbackFunction)device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + HUMIDITY_V2_CALLBACK_HUMIDITY];
	user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + HUMIDITY_V2_CALLBACK_HUMIDITY];
	callback = (Humidity_Callback *)packet;
	(void)callback; // avoid unused variable warning

	if (callback_function == NULL) {
		return;
	}

	callback->humidity = leconvert_uint16_from(callback->humidity);

	callback_function(callback->humidity, user_data);
}

static void humidity_v2_callback_wrapper_temperature(DevicePrivate *device_p, Packet *packet) {
	Temperature_CallbackFunction callback_function;
	void *user_data;
	Temperature_Callback *callback;

	if (packet->header.length != sizeof(Temperature_Callback)) {
		return; // silently ignoring callback with wrong length
	}

	callback_function = (Temperature_CallbackFunction)device_p->registered_callbacks[DEVICE_NUM_FUNCTION_IDS + HUMIDITY_V2_CALLBACK_TEMPERATURE];
	user_data = device_p->registered_callback_user_data[DEVICE_NUM_FUNCTION_IDS + HUMIDITY_V2_CALLBACK_TEMPERATURE];
	callback = (Temperature_Callback *)packet;
	(void)callback; // avoid unused variable warning

	if (callback_function == NULL) {
		return;
	}

	callback->temperature = leconvert_int16_from(callback->temperature);

	callback_function(callback->temperature, user_data);
}

void humidity_v2_create(HumidityV2 *humidity_v2, const char *uid, IPConnection *ipcon) {
	IPConnectionPrivate *ipcon_p = ipcon->p;
	DevicePrivate *device_p;

	device_create(humidity_v2, uid, ipcon_p, 2, 0, 2, HUMIDITY_V2_DEVICE_IDENTIFIER);

	device_p = humidity_v2->p;

	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_HUMIDITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_HUMIDITY_CALLBACK_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_HUMIDITY_CALLBACK_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_TEMPERATURE_CALLBACK_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_HEATER_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_HEATER_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_MOVING_AVERAGE_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_SAMPLES_PER_SECOND] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_SAMPLES_PER_SECOND] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_SPITFP_ERROR_COUNT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_BOOTLOADER_MODE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_BOOTLOADER_MODE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_WRITE_FIRMWARE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_SET_STATUS_LED_CONFIG] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_STATUS_LED_CONFIG] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_CHIP_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_RESET] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_WRITE_UID] = DEVICE_RESPONSE_EXPECTED_FALSE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_READ_UID] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	device_p->response_expected[HUMIDITY_V2_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	device_p->callback_wrappers[HUMIDITY_V2_CALLBACK_HUMIDITY] = humidity_v2_callback_wrapper_humidity;
	device_p->callback_wrappers[HUMIDITY_V2_CALLBACK_TEMPERATURE] = humidity_v2_callback_wrapper_temperature;

	ipcon_add_device(ipcon_p, device_p);
}

void humidity_v2_destroy(HumidityV2 *humidity_v2) {
	device_release(humidity_v2->p);
}

int humidity_v2_get_response_expected(HumidityV2 *humidity_v2, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(humidity_v2->p, function_id, ret_response_expected);
}

int humidity_v2_set_response_expected(HumidityV2 *humidity_v2, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(humidity_v2->p, function_id, response_expected);
}

int humidity_v2_set_response_expected_all(HumidityV2 *humidity_v2, bool response_expected) {
	return device_set_response_expected_all(humidity_v2->p, response_expected);
}

void humidity_v2_register_callback(HumidityV2 *humidity_v2, int16_t callback_id, void (*function)(void), void *user_data) {
	device_register_callback(humidity_v2->p, callback_id, function, user_data);
}

int humidity_v2_get_api_version(HumidityV2 *humidity_v2, uint8_t ret_api_version[3]) {
	return device_get_api_version(humidity_v2->p, ret_api_version);
}

int humidity_v2_get_humidity(HumidityV2 *humidity_v2, uint16_t *ret_humidity) {
	DevicePrivate *device_p = humidity_v2->p;
	GetHumidity_Request request;
	GetHumidity_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_HUMIDITY, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_humidity = leconvert_uint16_from(response.humidity);

	return ret;
}

int humidity_v2_set_humidity_callback_configuration(HumidityV2 *humidity_v2, uint32_t period, bool value_has_to_change, char option, uint16_t min, uint16_t max) {
	DevicePrivate *device_p = humidity_v2->p;
	SetHumidityCallbackConfiguration_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_HUMIDITY_CALLBACK_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);
	request.value_has_to_change = value_has_to_change ? 1 : 0;
	request.option = option;
	request.min = leconvert_uint16_to(min);
	request.max = leconvert_uint16_to(max);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_get_humidity_callback_configuration(HumidityV2 *humidity_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	DevicePrivate *device_p = humidity_v2->p;
	GetHumidityCallbackConfiguration_Request request;
	GetHumidityCallbackConfiguration_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_HUMIDITY_CALLBACK_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_period = leconvert_uint32_from(response.period);
	*ret_value_has_to_change = response.value_has_to_change != 0;
	*ret_option = response.option;
	*ret_min = leconvert_uint16_from(response.min);
	*ret_max = leconvert_uint16_from(response.max);

	return ret;
}

int humidity_v2_get_temperature(HumidityV2 *humidity_v2, int16_t *ret_temperature) {
	DevicePrivate *device_p = humidity_v2->p;
	GetTemperature_Request request;
	GetTemperature_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_TEMPERATURE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_temperature = leconvert_int16_from(response.temperature);

	return ret;
}

int humidity_v2_set_temperature_callback_configuration(HumidityV2 *humidity_v2, uint32_t period, bool value_has_to_change, char option, int16_t min, int16_t max) {
	DevicePrivate *device_p = humidity_v2->p;
	SetTemperatureCallbackConfiguration_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_TEMPERATURE_CALLBACK_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);
	request.value_has_to_change = value_has_to_change ? 1 : 0;
	request.option = option;
	request.min = leconvert_int16_to(min);
	request.max = leconvert_int16_to(max);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_get_temperature_callback_configuration(HumidityV2 *humidity_v2, uint32_t *ret_period, bool *ret_value_has_to_change, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	DevicePrivate *device_p = humidity_v2->p;
	GetTemperatureCallbackConfiguration_Request request;
	GetTemperatureCallbackConfiguration_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_TEMPERATURE_CALLBACK_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_period = leconvert_uint32_from(response.period);
	*ret_value_has_to_change = response.value_has_to_change != 0;
	*ret_option = response.option;
	*ret_min = leconvert_int16_from(response.min);
	*ret_max = leconvert_int16_from(response.max);

	return ret;
}

int humidity_v2_set_heater_configuration(HumidityV2 *humidity_v2, uint8_t heater_config) {
	DevicePrivate *device_p = humidity_v2->p;
	SetHeaterConfiguration_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_HEATER_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.heater_config = heater_config;

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_get_heater_configuration(HumidityV2 *humidity_v2, uint8_t *ret_heater_config) {
	DevicePrivate *device_p = humidity_v2->p;
	GetHeaterConfiguration_Request request;
	GetHeaterConfiguration_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_HEATER_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_heater_config = response.heater_config;

	return ret;
}

int humidity_v2_set_moving_average_configuration(HumidityV2 *humidity_v2, uint16_t moving_average_length_humidity, uint16_t moving_average_length_temperature) {
	DevicePrivate *device_p = humidity_v2->p;
	SetMovingAverageConfiguration_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_MOVING_AVERAGE_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.moving_average_length_humidity = leconvert_uint16_to(moving_average_length_humidity);
	request.moving_average_length_temperature = leconvert_uint16_to(moving_average_length_temperature);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_get_moving_average_configuration(HumidityV2 *humidity_v2, uint16_t *ret_moving_average_length_humidity, uint16_t *ret_moving_average_length_temperature) {
	DevicePrivate *device_p = humidity_v2->p;
	GetMovingAverageConfiguration_Request request;
	GetMovingAverageConfiguration_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_MOVING_AVERAGE_CONFIGURATION, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_moving_average_length_humidity = leconvert_uint16_from(response.moving_average_length_humidity);
	*ret_moving_average_length_temperature = leconvert_uint16_from(response.moving_average_length_temperature);

	return ret;
}

int humidity_v2_set_samples_per_second(HumidityV2 *humidity_v2, uint8_t sps) {
	DevicePrivate *device_p = humidity_v2->p;
	SetSamplesPerSecond_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_SAMPLES_PER_SECOND, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.sps = sps;

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_get_samples_per_second(HumidityV2 *humidity_v2, uint8_t *ret_sps) {
	DevicePrivate *device_p = humidity_v2->p;
	GetSamplesPerSecond_Request request;
	GetSamplesPerSecond_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_SAMPLES_PER_SECOND, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_sps = response.sps;

	return ret;
}

int humidity_v2_get_spitfp_error_count(HumidityV2 *humidity_v2, uint32_t *ret_error_count_ack_checksum, uint32_t *ret_error_count_message_checksum, uint32_t *ret_error_count_frame, uint32_t *ret_error_count_overflow) {
	DevicePrivate *device_p = humidity_v2->p;
	GetSPITFPErrorCount_Request request;
	GetSPITFPErrorCount_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_SPITFP_ERROR_COUNT, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_error_count_ack_checksum = leconvert_uint32_from(response.error_count_ack_checksum);
	*ret_error_count_message_checksum = leconvert_uint32_from(response.error_count_message_checksum);
	*ret_error_count_frame = leconvert_uint32_from(response.error_count_frame);
	*ret_error_count_overflow = leconvert_uint32_from(response.error_count_overflow);

	return ret;
}

int humidity_v2_set_bootloader_mode(HumidityV2 *humidity_v2, uint8_t mode, uint8_t *ret_status) {
	DevicePrivate *device_p = humidity_v2->p;
	SetBootloaderMode_Request request;
	SetBootloaderMode_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_BOOTLOADER_MODE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.mode = mode;

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_status = response.status;

	return ret;
}

int humidity_v2_get_bootloader_mode(HumidityV2 *humidity_v2, uint8_t *ret_mode) {
	DevicePrivate *device_p = humidity_v2->p;
	GetBootloaderMode_Request request;
	GetBootloaderMode_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_BOOTLOADER_MODE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_mode = response.mode;

	return ret;
}

int humidity_v2_set_write_firmware_pointer(HumidityV2 *humidity_v2, uint32_t pointer) {
	DevicePrivate *device_p = humidity_v2->p;
	SetWriteFirmwarePointer_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_WRITE_FIRMWARE_POINTER, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.pointer = leconvert_uint32_to(pointer);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_write_firmware(HumidityV2 *humidity_v2, uint8_t data[64], uint8_t *ret_status) {
	DevicePrivate *device_p = humidity_v2->p;
	WriteFirmware_Request request;
	WriteFirmware_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_WRITE_FIRMWARE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	memcpy(request.data, data, 64 * sizeof(uint8_t));

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_status = response.status;

	return ret;
}

int humidity_v2_set_status_led_config(HumidityV2 *humidity_v2, uint8_t config) {
	DevicePrivate *device_p = humidity_v2->p;
	SetStatusLEDConfig_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_SET_STATUS_LED_CONFIG, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.config = config;

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_get_status_led_config(HumidityV2 *humidity_v2, uint8_t *ret_config) {
	DevicePrivate *device_p = humidity_v2->p;
	GetStatusLEDConfig_Request request;
	GetStatusLEDConfig_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_STATUS_LED_CONFIG, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_config = response.config;

	return ret;
}

int humidity_v2_get_chip_temperature(HumidityV2 *humidity_v2, int16_t *ret_temperature) {
	DevicePrivate *device_p = humidity_v2->p;
	GetChipTemperature_Request request;
	GetChipTemperature_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_CHIP_TEMPERATURE, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_temperature = leconvert_int16_from(response.temperature);

	return ret;
}

int humidity_v2_reset(HumidityV2 *humidity_v2) {
	DevicePrivate *device_p = humidity_v2->p;
	Reset_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_RESET, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_write_uid(HumidityV2 *humidity_v2, uint32_t uid) {
	DevicePrivate *device_p = humidity_v2->p;
	WriteUID_Request request;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_WRITE_UID, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	request.uid = leconvert_uint32_to(uid);

	ret = device_send_request(device_p, (Packet *)&request, NULL, 0);

	return ret;
}

int humidity_v2_read_uid(HumidityV2 *humidity_v2, uint32_t *ret_uid) {
	DevicePrivate *device_p = humidity_v2->p;
	ReadUID_Request request;
	ReadUID_Response response;
	int ret;

	ret = device_check_validity(device_p);

	if (ret < 0) {
		return ret;
	}

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_READ_UID, device_p->ipcon_p, device_p);

	if (ret < 0) {
		return ret;
	}

	ret = device_send_request(device_p, (Packet *)&request, (Packet *)&response, sizeof(response));

	if (ret < 0) {
		return ret;
	}

	*ret_uid = leconvert_uint32_from(response.uid);

	return ret;
}

int humidity_v2_get_identity(HumidityV2 *humidity_v2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	DevicePrivate *device_p = humidity_v2->p;
	GetIdentity_Request request;
	GetIdentity_Response response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), HUMIDITY_V2_FUNCTION_GET_IDENTITY, device_p->ipcon_p, device_p);

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
