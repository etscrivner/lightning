  #include <lightningd/log.h>

static void wallet_fatal(const char *fmt, ...);
#define fatal wallet_fatal
#include "test_utils.h"

static void db_log_(struct log *log UNUSED, enum log_level level UNUSED, const char *fmt UNUSED, ...)
{
}
#define log_ db_log_

#include "wallet/wallet.c"
#include "lightningd/htlc_end.c"
#include "lightningd/peer_control.c"
#include "lightningd/channel.c"

#include "wallet/db.c"

#include <ccan/mem/mem.h>
#include <ccan/tal/str/str.h>
#include <ccan/structeq/structeq.h>
#include <common/memleak.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

bool deprecated_apis = true;

/* AUTOGENERATED MOCKS START */
/* Generated stub for bip32_pubkey */
bool bip32_pubkey(const struct ext_key *bip32_base UNNEEDED,
		  struct pubkey *pubkey UNNEEDED, u32 index UNNEEDED)
{ fprintf(stderr, "bip32_pubkey called!\n"); abort(); }
/* Generated stub for bitcoind_gettxout */
void bitcoind_gettxout(struct bitcoind *bitcoind UNNEEDED,
		       const struct bitcoin_txid *txid UNNEEDED, const u32 outnum UNNEEDED,
		       void (*cb)(struct bitcoind *bitcoind UNNEEDED,
				  const struct bitcoin_tx_output *txout UNNEEDED,
				  void *arg) UNNEEDED,
		       void *arg UNNEEDED)
{ fprintf(stderr, "bitcoind_gettxout called!\n"); abort(); }
/* Generated stub for broadcast_tx */
void broadcast_tx(struct chain_topology *topo UNNEEDED,
		  struct channel *channel UNNEEDED, const struct bitcoin_tx *tx UNNEEDED,
		  void (*failed)(struct channel *channel UNNEEDED,
				 int exitstatus UNNEEDED,
				 const char *err))
{ fprintf(stderr, "broadcast_tx called!\n"); abort(); }
/* Generated stub for command_fail */
void  command_fail(struct command *cmd UNNEEDED, const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "command_fail called!\n"); abort(); }
/* Generated stub for command_still_pending */
void command_still_pending(struct command *cmd UNNEEDED)
{ fprintf(stderr, "command_still_pending called!\n"); abort(); }
/* Generated stub for command_success */
void command_success(struct command *cmd UNNEEDED, struct json_result *response UNNEEDED)
{ fprintf(stderr, "command_success called!\n"); abort(); }
/* Generated stub for connect_failed */
void connect_failed(struct lightningd *ld UNNEEDED, const struct pubkey *id UNNEEDED,
		    const char *error UNNEEDED)
{ fprintf(stderr, "connect_failed called!\n"); abort(); }
/* Generated stub for connect_succeeded */
void connect_succeeded(struct lightningd *ld UNNEEDED, const struct pubkey *id UNNEEDED)
{ fprintf(stderr, "connect_succeeded called!\n"); abort(); }
/* Generated stub for derive_basepoints */
bool derive_basepoints(const struct privkey *seed UNNEEDED,
		       struct pubkey *funding_pubkey UNNEEDED,
		       struct basepoints *basepoints UNNEEDED,
		       struct secrets *secrets UNNEEDED,
		       struct sha256 *shaseed UNNEEDED)
{ fprintf(stderr, "derive_basepoints called!\n"); abort(); }
/* Generated stub for extract_channel_id */
bool extract_channel_id(const u8 *in_pkt UNNEEDED, struct channel_id *channel_id UNNEEDED)
{ fprintf(stderr, "extract_channel_id called!\n"); abort(); }
/* Generated stub for fromwire_gossip_getpeers_reply */
bool fromwire_gossip_getpeers_reply(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, struct pubkey **id UNNEEDED, struct wireaddr **addr UNNEEDED)
{ fprintf(stderr, "fromwire_gossip_getpeers_reply called!\n"); abort(); }
/* Generated stub for fromwire_gossip_peer_connected */
bool fromwire_gossip_peer_connected(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, struct pubkey *id UNNEEDED, struct wireaddr *addr UNNEEDED, struct crypto_state *crypto_state UNNEEDED, u64 *gossip_index UNNEEDED, u8 **gfeatures UNNEEDED, u8 **lfeatures UNNEEDED)
{ fprintf(stderr, "fromwire_gossip_peer_connected called!\n"); abort(); }
/* Generated stub for funding_spent */
enum watch_result funding_spent(struct channel *channel UNNEEDED,
				const struct bitcoin_tx *tx UNNEEDED,
				size_t input_num UNNEEDED,
				const struct block *block UNNEEDED)
{ fprintf(stderr, "funding_spent called!\n"); abort(); }
/* Generated stub for get_feerate */
u32 get_feerate(const struct chain_topology *topo UNNEEDED, enum feerate feerate UNNEEDED)
{ fprintf(stderr, "get_feerate called!\n"); abort(); }
/* Generated stub for get_supported_global_features */
u8 *get_supported_global_features(const tal_t *ctx UNNEEDED)
{ fprintf(stderr, "get_supported_global_features called!\n"); abort(); }
/* Generated stub for get_supported_local_features */
u8 *get_supported_local_features(const tal_t *ctx UNNEEDED)
{ fprintf(stderr, "get_supported_local_features called!\n"); abort(); }
/* Generated stub for invoices_create */
const struct invoice *invoices_create(struct invoices *invoices UNNEEDED,
				      u64 *msatoshi TAKES UNNEEDED,
				      const char *label TAKES UNNEEDED,
				      u64 expiry UNNEEDED)
{ fprintf(stderr, "invoices_create called!\n"); abort(); }
/* Generated stub for invoices_delete */
bool invoices_delete(struct invoices *invoices UNNEEDED,
		     const struct invoice *invoice UNNEEDED)
{ fprintf(stderr, "invoices_delete called!\n"); abort(); }
/* Generated stub for invoices_find_by_label */
const struct invoice *invoices_find_by_label(struct invoices *invoices UNNEEDED,
					     const char *label UNNEEDED)
{ fprintf(stderr, "invoices_find_by_label called!\n"); abort(); }
/* Generated stub for invoices_find_unpaid */
const struct invoice *invoices_find_unpaid(struct invoices *invoices UNNEEDED,
					   const struct sha256 *rhash UNNEEDED)
{ fprintf(stderr, "invoices_find_unpaid called!\n"); abort(); }
/* Generated stub for invoices_iterate */
const struct invoice *invoices_iterate(struct invoices *invoices UNNEEDED,
				       const struct invoice *invoice UNNEEDED)
{ fprintf(stderr, "invoices_iterate called!\n"); abort(); }
/* Generated stub for invoices_load */
bool invoices_load(struct invoices *invoices UNNEEDED)
{ fprintf(stderr, "invoices_load called!\n"); abort(); }
/* Generated stub for invoices_new */
struct invoices *invoices_new(const tal_t *ctx UNNEEDED,
			      struct db *db UNNEEDED,
			      struct log *log UNNEEDED,
			      struct timers *timers UNNEEDED)
{ fprintf(stderr, "invoices_new called!\n"); abort(); }
/* Generated stub for invoices_resolve */
void invoices_resolve(struct invoices *invoices UNNEEDED,
		      const struct invoice *invoice UNNEEDED,
		      u64 msatoshi_received UNNEEDED)
{ fprintf(stderr, "invoices_resolve called!\n"); abort(); }
/* Generated stub for invoices_waitany */
void invoices_waitany(const tal_t *ctx UNNEEDED,
		      struct invoices *invoices UNNEEDED,
		      u64 lastpay_index UNNEEDED,
		      void (*cb)(const struct invoice * UNNEEDED, void*) UNNEEDED,
		      void *cbarg UNNEEDED)
{ fprintf(stderr, "invoices_waitany called!\n"); abort(); }
/* Generated stub for invoices_waitone */
void invoices_waitone(const tal_t *ctx UNNEEDED,
		      struct invoices *invoices UNNEEDED,
		      struct invoice const *invoice UNNEEDED,
		      void (*cb)(const struct invoice * UNNEEDED, void*) UNNEEDED,
		      void *cbarg UNNEEDED)
{ fprintf(stderr, "invoices_waitone called!\n"); abort(); }
/* Generated stub for json_add_bool */
void json_add_bool(struct json_result *result UNNEEDED, const char *fieldname UNNEEDED,
		   bool value UNNEEDED)
{ fprintf(stderr, "json_add_bool called!\n"); abort(); }
/* Generated stub for json_add_hex */
void json_add_hex(struct json_result *result UNNEEDED, const char *fieldname UNNEEDED,
		  const void *data UNNEEDED, size_t len UNNEEDED)
{ fprintf(stderr, "json_add_hex called!\n"); abort(); }
/* Generated stub for json_add_log */
void json_add_log(struct json_result *result UNNEEDED,
		  const struct log_book *lr UNNEEDED, enum log_level minlevel UNNEEDED)
{ fprintf(stderr, "json_add_log called!\n"); abort(); }
/* Generated stub for json_add_num */
void json_add_num(struct json_result *result UNNEEDED, const char *fieldname UNNEEDED,
		  unsigned int value UNNEEDED)
{ fprintf(stderr, "json_add_num called!\n"); abort(); }
/* Generated stub for json_add_pubkey */
void json_add_pubkey(struct json_result *response UNNEEDED,
		     const char *fieldname UNNEEDED,
		     const struct pubkey *key UNNEEDED)
{ fprintf(stderr, "json_add_pubkey called!\n"); abort(); }
/* Generated stub for json_add_short_channel_id */
void json_add_short_channel_id(struct json_result *response UNNEEDED,
			       const char *fieldname UNNEEDED,
			       const struct short_channel_id *id UNNEEDED)
{ fprintf(stderr, "json_add_short_channel_id called!\n"); abort(); }
/* Generated stub for json_add_string */
void json_add_string(struct json_result *result UNNEEDED, const char *fieldname UNNEEDED, const char *value UNNEEDED)
{ fprintf(stderr, "json_add_string called!\n"); abort(); }
/* Generated stub for json_add_txid */
void json_add_txid(struct json_result *result UNNEEDED, const char *fieldname UNNEEDED,
		   const struct bitcoin_txid *txid UNNEEDED)
{ fprintf(stderr, "json_add_txid called!\n"); abort(); }
/* Generated stub for json_add_u64 */
void json_add_u64(struct json_result *result UNNEEDED, const char *fieldname UNNEEDED,
		  uint64_t value UNNEEDED)
{ fprintf(stderr, "json_add_u64 called!\n"); abort(); }
/* Generated stub for json_add_uncommitted_channel */
void json_add_uncommitted_channel(struct json_result *response UNNEEDED,
				  const struct uncommitted_channel *uc UNNEEDED)
{ fprintf(stderr, "json_add_uncommitted_channel called!\n"); abort(); }
/* Generated stub for json_array_end */
void json_array_end(struct json_result *ptr UNNEEDED)
{ fprintf(stderr, "json_array_end called!\n"); abort(); }
/* Generated stub for json_array_start */
void json_array_start(struct json_result *ptr UNNEEDED, const char *fieldname UNNEEDED)
{ fprintf(stderr, "json_array_start called!\n"); abort(); }
/* Generated stub for json_get_params */
bool json_get_params(struct command *cmd UNNEEDED,
		     const char *buffer UNNEEDED, const jsmntok_t param[] UNNEEDED, ...)
{ fprintf(stderr, "json_get_params called!\n"); abort(); }
/* Generated stub for json_object_end */
void json_object_end(struct json_result *ptr UNNEEDED)
{ fprintf(stderr, "json_object_end called!\n"); abort(); }
/* Generated stub for json_object_start */
void json_object_start(struct json_result *ptr UNNEEDED, const char *fieldname UNNEEDED)
{ fprintf(stderr, "json_object_start called!\n"); abort(); }
/* Generated stub for json_tok_bool */
bool json_tok_bool(const char *buffer UNNEEDED, const jsmntok_t *tok UNNEEDED, bool *b UNNEEDED)
{ fprintf(stderr, "json_tok_bool called!\n"); abort(); }
/* Generated stub for json_tok_loglevel */
bool json_tok_loglevel(const char *buffer UNNEEDED, const jsmntok_t *tok UNNEEDED,
		       enum log_level *level UNNEEDED)
{ fprintf(stderr, "json_tok_loglevel called!\n"); abort(); }
/* Generated stub for json_tok_pubkey */
bool json_tok_pubkey(const char *buffer UNNEEDED, const jsmntok_t *tok UNNEEDED,
		     struct pubkey *pubkey UNNEEDED)
{ fprintf(stderr, "json_tok_pubkey called!\n"); abort(); }
/* Generated stub for json_tok_short_channel_id */
bool json_tok_short_channel_id(const char *buffer UNNEEDED, const jsmntok_t *tok UNNEEDED,
			       struct short_channel_id *scid UNNEEDED)
{ fprintf(stderr, "json_tok_short_channel_id called!\n"); abort(); }
/* Generated stub for kill_uncommitted_channel */
void kill_uncommitted_channel(struct uncommitted_channel *uc UNNEEDED,
			      const char *why UNNEEDED)
{ fprintf(stderr, "kill_uncommitted_channel called!\n"); abort(); }
/* Generated stub for locate_tx */
struct txlocator *locate_tx(const void *ctx UNNEEDED, const struct chain_topology *topo UNNEEDED, const struct bitcoin_txid *txid UNNEEDED)
{ fprintf(stderr, "locate_tx called!\n"); abort(); }
/* Generated stub for log_add */
void log_add(struct log *log UNNEEDED, const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "log_add called!\n"); abort(); }
/* Generated stub for log_io */
void log_io(struct log *log UNNEEDED, enum log_level dir UNNEEDED, const char *comment UNNEEDED,
	    const void *data UNNEEDED, size_t len UNNEEDED)
{ fprintf(stderr, "log_io called!\n"); abort(); }
/* Generated stub for logv_add */
void logv_add(struct log *log UNNEEDED, const char *fmt UNNEEDED, va_list ap UNNEEDED)
{ fprintf(stderr, "logv_add called!\n"); abort(); }
/* Generated stub for new_json_result */
struct json_result *new_json_result(const tal_t *ctx UNNEEDED)
{ fprintf(stderr, "new_json_result called!\n"); abort(); }
/* Generated stub for null_response */
struct json_result *null_response(const tal_t *ctx UNNEEDED)
{ fprintf(stderr, "null_response called!\n"); abort(); }
/* Generated stub for peer_accept_channel */
u8 *peer_accept_channel(struct lightningd *ld UNNEEDED,
			const struct pubkey *peer_id UNNEEDED,
			const struct wireaddr *addr UNNEEDED,
			const struct crypto_state *cs UNNEEDED,
			u64 gossip_index UNNEEDED,
			const u8 *gfeatures UNNEEDED, const u8 *lfeatures UNNEEDED,
			int peer_fd UNNEEDED, int gossip_fd UNNEEDED,
			const struct channel_id *channel_id UNNEEDED,
			const u8 *open_msg UNNEEDED)
{ fprintf(stderr, "peer_accept_channel called!\n"); abort(); }
/* Generated stub for peer_start_channeld */
bool peer_start_channeld(struct channel *channel UNNEEDED,
			 const struct crypto_state *cs UNNEEDED,
			 u64 gossip_index UNNEEDED,
			 int peer_fd UNNEEDED, int gossip_fd UNNEEDED,
			 const u8 *funding_signed UNNEEDED,
			 bool reconnected UNNEEDED)
{ fprintf(stderr, "peer_start_channeld called!\n"); abort(); }
/* Generated stub for peer_start_closingd */
void peer_start_closingd(struct channel *channel UNNEEDED,
			 struct crypto_state *cs UNNEEDED,
			 u64 gossip_index UNNEEDED,
			 int peer_fd UNNEEDED, int gossip_fd UNNEEDED,
			 bool reconnected UNNEEDED)
{ fprintf(stderr, "peer_start_closingd called!\n"); abort(); }
/* Generated stub for sanitize_error */
char *sanitize_error(const tal_t *ctx UNNEEDED, const u8 *errmsg UNNEEDED,
		     struct channel_id *channel_id UNNEEDED)
{ fprintf(stderr, "sanitize_error called!\n"); abort(); }
/* Generated stub for subd_release_channel */
void subd_release_channel(struct subd *owner UNNEEDED, void *channel UNNEEDED)
{ fprintf(stderr, "subd_release_channel called!\n"); abort(); }
/* Generated stub for subd_req_ */
void subd_req_(const tal_t *ctx UNNEEDED,
	       struct subd *sd UNNEEDED,
	       const u8 *msg_out UNNEEDED,
	       int fd_out UNNEEDED, size_t num_fds_in UNNEEDED,
	       void (*replycb)(struct subd * UNNEEDED, const u8 * UNNEEDED, const int * UNNEEDED, void *) UNNEEDED,
	       void *replycb_data UNNEEDED)
{ fprintf(stderr, "subd_req_ called!\n"); abort(); }
/* Generated stub for subd_send_fd */
void subd_send_fd(struct subd *sd UNNEEDED, int fd UNNEEDED)
{ fprintf(stderr, "subd_send_fd called!\n"); abort(); }
/* Generated stub for subd_send_msg */
void subd_send_msg(struct subd *sd UNNEEDED, const u8 *msg_out UNNEEDED)
{ fprintf(stderr, "subd_send_msg called!\n"); abort(); }
/* Generated stub for towire_channel_dev_reenable_commit */
u8 *towire_channel_dev_reenable_commit(const tal_t *ctx UNNEEDED)
{ fprintf(stderr, "towire_channel_dev_reenable_commit called!\n"); abort(); }
/* Generated stub for towire_channel_funding_announce_depth */
u8 *towire_channel_funding_announce_depth(const tal_t *ctx UNNEEDED)
{ fprintf(stderr, "towire_channel_funding_announce_depth called!\n"); abort(); }
/* Generated stub for towire_channel_funding_locked */
u8 *towire_channel_funding_locked(const tal_t *ctx UNNEEDED, const struct short_channel_id *short_channel_id UNNEEDED)
{ fprintf(stderr, "towire_channel_funding_locked called!\n"); abort(); }
/* Generated stub for towire_channel_send_shutdown */
u8 *towire_channel_send_shutdown(const tal_t *ctx UNNEEDED, const u8 *scriptpubkey UNNEEDED)
{ fprintf(stderr, "towire_channel_send_shutdown called!\n"); abort(); }
/* Generated stub for towire_error */
u8 *towire_error(const tal_t *ctx UNNEEDED, const struct channel_id *channel_id UNNEEDED, const u8 *data UNNEEDED)
{ fprintf(stderr, "towire_error called!\n"); abort(); }
/* Generated stub for towire_errorfmt */
u8 *towire_errorfmt(const tal_t *ctx UNNEEDED,
		    const struct channel_id *channel UNNEEDED,
		    const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "towire_errorfmt called!\n"); abort(); }
/* Generated stub for towire_gossipctl_hand_back_peer */
u8 *towire_gossipctl_hand_back_peer(const tal_t *ctx UNNEEDED, const struct pubkey *id UNNEEDED, const struct crypto_state *crypto_state UNNEEDED, u64 gossip_index UNNEEDED, const u8 *msg UNNEEDED)
{ fprintf(stderr, "towire_gossipctl_hand_back_peer called!\n"); abort(); }
/* Generated stub for towire_gossipctl_peer_addrhint */
u8 *towire_gossipctl_peer_addrhint(const tal_t *ctx UNNEEDED, const struct pubkey *id UNNEEDED, const struct wireaddr *addr UNNEEDED)
{ fprintf(stderr, "towire_gossipctl_peer_addrhint called!\n"); abort(); }
/* Generated stub for towire_gossipctl_reach_peer */
u8 *towire_gossipctl_reach_peer(const tal_t *ctx UNNEEDED, const struct pubkey *id UNNEEDED)
{ fprintf(stderr, "towire_gossipctl_reach_peer called!\n"); abort(); }
/* Generated stub for towire_gossip_disable_channel */
u8 *towire_gossip_disable_channel(const tal_t *ctx UNNEEDED, const struct short_channel_id *short_channel_id UNNEEDED, u8 direction UNNEEDED, bool active UNNEEDED)
{ fprintf(stderr, "towire_gossip_disable_channel called!\n"); abort(); }
/* Generated stub for towire_gossip_getpeers_request */
u8 *towire_gossip_getpeers_request(const tal_t *ctx UNNEEDED, const struct pubkey *id UNNEEDED)
{ fprintf(stderr, "towire_gossip_getpeers_request called!\n"); abort(); }
/* Generated stub for txfilter_add_scriptpubkey */
void txfilter_add_scriptpubkey(struct txfilter *filter UNNEEDED, u8 *script UNNEEDED)
{ fprintf(stderr, "txfilter_add_scriptpubkey called!\n"); abort(); }
/* Generated stub for unsupported_features */
bool unsupported_features(const u8 *gfeatures UNNEEDED, const u8 *lfeatures UNNEEDED)
{ fprintf(stderr, "unsupported_features called!\n"); abort(); }
/* Generated stub for watch_txid */
struct txwatch *watch_txid(const tal_t *ctx UNNEEDED,
			   struct chain_topology *topo UNNEEDED,
			   struct channel *channel UNNEEDED,
			   const struct bitcoin_txid *txid UNNEEDED,
			   enum watch_result (*cb)(struct channel *channel UNNEEDED,
						    const struct bitcoin_tx * UNNEEDED,
						   unsigned int depth))
{ fprintf(stderr, "watch_txid called!\n"); abort(); }
/* Generated stub for watch_txo */
struct txowatch *watch_txo(const tal_t *ctx UNNEEDED,
			   struct chain_topology *topo UNNEEDED,
			   struct channel *channel UNNEEDED,
			   const struct bitcoin_txid *txid UNNEEDED,
			   unsigned int output UNNEEDED,
			   enum watch_result (*cb)(struct channel *channel UNNEEDED,
						   const struct bitcoin_tx *tx UNNEEDED,
						   size_t input_num UNNEEDED,
						   const struct block *block))
{ fprintf(stderr, "watch_txo called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

#if DEVELOPER
bool dev_disconnect_permanent(struct lightningd *ld UNNEEDED)
{ fprintf(stderr, "dev_disconnect_permanent called!\n"); abort(); }
#endif

static char *wallet_err;
static void wallet_fatal(const char *fmt, ...)
{
	va_list ap;

	/* Fail hard if we're complaining about not being in transaction */
	assert(!strstarts(fmt, "No longer in transaction"));

	/* Fail hard if we're complaining about not being in transaction */
	assert(!strstarts(fmt, "No longer in transaction"));

	va_start(ap, fmt);
	wallet_err = tal_vfmt(NULL, fmt, ap);
	va_end(ap);
}

#define transaction_wrap(db, ...)					\
	(db_begin_transaction(db), __VA_ARGS__, db_commit_transaction(db), wallet_err == NULL)

enum log_level get_log_level(struct log_book *lr UNNEEDED)
{
	return LOG_DBG;
}

struct log *new_log(const tal_t *ctx UNNEEDED, struct log_book *record UNNEEDED, const char *fmt UNNEEDED, ...)
{
	return NULL;
}

struct log_book *new_log_book(size_t max_mem UNNEEDED,
			      enum log_level printlevel UNNEEDED)
{
	return NULL;
}

void set_log_outfn_(struct log_book *lr UNNEEDED,
		    void (*print)(const char *prefix UNNEEDED,
				  enum log_level level UNNEEDED,
				  bool continued UNNEEDED,
				  const struct timeabs *time UNNEEDED,
				  const char *str UNNEEDED,
				  const u8 *io UNNEEDED,
				  void *arg) UNNEEDED,
		    void *arg UNNEEDED)
{
}

const char *log_prefix(const struct log *log UNNEEDED)
{
	return "";
}

/**
 * mempat -- Set the memory to a pattern
 *
 * Used mainly to check that we don't mix fields while
 * serializing/unserializing.
 */
static void mempat(void *dst, size_t len)
{
	static int n = 0;
	u8 *p = (u8*)dst;
	for(int i=0 ; i < len; ++i)
		p[i] = n % 251; /* Prime */
}

static struct wallet *create_test_wallet(struct lightningd *ld, const tal_t *ctx)
{
	char filename[] = "/tmp/ldb-XXXXXX";
	int fd = mkstemp(filename);
	struct wallet *w = tal(ctx, struct wallet);
	CHECK_MSG(fd != -1, "Unable to generate temp filename");
	close(fd);

	w->db = db_open(w, filename);

	ltmp = tal_tmpctx(ctx);
	list_head_init(&w->unstored_payments);
	w->ld = ld;

	CHECK_MSG(w->db, "Failed opening the db");
	db_migrate(w->db, w->log);
	CHECK_MSG(!wallet_err, "DB migration failed");
	w->max_channel_dbid = 0;

	return w;
}

static bool test_wallet_outputs(void)
{
	char filename[] = "/tmp/ldb-XXXXXX";
	struct utxo u;
	int fd = mkstemp(filename);
	CHECK_MSG(fd != -1, "Unable to generate temp filename");
	close(fd);

	struct wallet *w = tal(NULL, struct wallet);
	struct pubkey pk;
	u64 fee_estimate, change_satoshis;
	const struct utxo **utxos;

	w->db = db_open(w, filename);
	CHECK_MSG(w->db, "Failed opening the db");
	db_migrate(w->db, NULL);
	CHECK_MSG(!wallet_err, "DB migration failed");

	memset(&u, 0, sizeof(u));
	u.amount = 1;
	pubkey_from_der(tal_hexdata(w, "02a1633cafcc01ebfb6d78e39f687a1f0995c62fc95f51ead10a02ee0be551b5dc", 66), 33, &pk);

	db_begin_transaction(w->db);

	/* Should work, it's the first time we add it */
	CHECK_MSG(wallet_add_utxo(w, &u, p2sh_wpkh),
		  "wallet_add_utxo failed on first add");

	/* Should fail, we already have that UTXO */
	CHECK_MSG(!wallet_add_utxo(w, &u, p2sh_wpkh),
		  "wallet_add_utxo succeeded on second add");

	/* Attempt to save an UTXO with close_info set */
	memset(&u.txid, 1, sizeof(u.txid));
	u.close_info = tal(w, struct unilateral_close_info);
	u.close_info->channel_id = 42;
	u.close_info->peer_id = pk;
	u.close_info->commitment_point = pk;
	CHECK_MSG(wallet_add_utxo(w, &u, p2sh_wpkh),
		  "wallet_add_utxo with close_info");

	/* Now select them */
	utxos = wallet_select_coins(w, w, 2, 0, 21, &fee_estimate, &change_satoshis);
	CHECK(utxos && tal_count(utxos) == 2);

	u = *utxos[1];
	CHECK(u.close_info->channel_id == 42 &&
	      pubkey_eq(&u.close_info->commitment_point, &pk) &&
	      pubkey_eq(&u.close_info->peer_id, &pk));
	/* Now un-reserve them for the tests below */
	tal_free(utxos);


	/* Attempt to reserve the utxo */
	CHECK_MSG(wallet_update_output_status(w, &u.txid, u.outnum,
					      output_state_available,
					      output_state_reserved),
		  "could not reserve available output");

	/* Reserving twice should fail */
	CHECK_MSG(!wallet_update_output_status(w, &u.txid, u.outnum,
					       output_state_available,
					       output_state_reserved),
		  "could reserve already reserved output");

	/* Un-reserving should work */
	CHECK_MSG(wallet_update_output_status(w, &u.txid, u.outnum,
					      output_state_reserved,
					      output_state_available),
		  "could not unreserve reserved output");

	/* Switching from any to something else */
	CHECK_MSG(wallet_update_output_status(w, &u.txid, u.outnum,
					      output_state_any,
					      output_state_spent),
		  "could not change output state ignoring oldstate");

	db_commit_transaction(w->db);

	tal_free(w);
	return true;
}

static bool test_shachain_crud(void)
{
	struct wallet_shachain a, b;
	char filename[] = "/tmp/ldb-XXXXXX";
	int fd = mkstemp(filename);
	struct wallet *w = tal(NULL, struct wallet);
	struct sha256 seed, hash;
	uint64_t index = UINT64_MAX >> (64 - SHACHAIN_BITS);

	w->db = db_open(w, filename);
	CHECK_MSG(w->db, "Failed opening the db");
	db_migrate(w->db, NULL);
	CHECK_MSG(!wallet_err, "DB migration failed");

	CHECK_MSG(fd != -1, "Unable to generate temp filename");
	close(fd);
	memset(&seed, 'A', sizeof(seed));

	memset(&a, 0, sizeof(a));
	memset(&b, 0, sizeof(b));

	w->db = db_open(w, filename);
	db_begin_transaction(w->db);
	CHECK_MSG(!wallet_err, "db_begin_transaction failed");
	wallet_shachain_init(w, &a);
	CHECK(!wallet_err);

	CHECK(a.id == 1);

	CHECK(a.chain.num_valid == 0);
	CHECK(shachain_next_index(&a.chain) == index);

	for (int i=0; i<100; i++) {
		shachain_from_seed(&seed, index, &hash);
		CHECK(wallet_shachain_add_hash(w, &a, index, &hash));
		index--;
	}

	CHECK(wallet_shachain_load(w, a.id, &b));
	CHECK_MSG(memcmp(&a, &b, sizeof(a)) == 0, "Loading from database doesn't match");

	db_commit_transaction(w->db);
	CHECK(!wallet_err);
	tal_free(w);
	return true;
}

static bool bitcoin_tx_eq(const struct bitcoin_tx *tx1,
			  const struct bitcoin_tx *tx2)
{
	u8 *lin1, *lin2;
	bool eq;
	lin1 = linearize_tx(NULL, tx1);
	lin2 = linearize_tx(lin1, tx2);
	eq = memeq(lin1, tal_len(lin1), lin2, tal_len(lin2));
	tal_free(lin1);
	return eq;
}

static bool channelseq(struct channel *c1, struct channel *c2)
{
	struct peer *p1 = c1->peer, *p2 = c2->peer;
	struct channel_info *ci1 = &c1->channel_info, *ci2 = &c2->channel_info;
	struct changed_htlc *lc1 = c1->last_sent_commit, *lc2 = c2->last_sent_commit;
	CHECK(c1->dbid == c2->dbid);
	CHECK(c1->first_blocknum == c2->first_blocknum);
	CHECK(c1->peer->dbid == c2->peer->dbid);
	CHECK(c1->peer == c2->peer);
	CHECK(c1->their_shachain.id == c2->their_shachain.id);
	CHECK_MSG(pubkey_eq(&p1->id, &p2->id), "NodeIDs do not match");
	CHECK((c1->scid == NULL && c2->scid == NULL) || short_channel_id_eq(c1->scid, c2->scid));
	CHECK(c1->our_msatoshi == c2->our_msatoshi);
	CHECK((c1->remote_shutdown_scriptpubkey == NULL && c2->remote_shutdown_scriptpubkey == NULL) || memeq(
		      c1->remote_shutdown_scriptpubkey,
		      tal_len(c1->remote_shutdown_scriptpubkey),
		      c2->remote_shutdown_scriptpubkey,
		      tal_len(c2->remote_shutdown_scriptpubkey)));
	CHECK(memeq(
		      &c1->funding_txid,
		      sizeof(struct sha256_double),
		      &c2->funding_txid,
		      sizeof(struct sha256_double)));
	CHECK(pubkey_eq(&ci1->remote_fundingkey, &ci2->remote_fundingkey));
	CHECK(pubkey_eq(&ci1->theirbase.revocation, &ci2->theirbase.revocation));
	CHECK(pubkey_eq(&ci1->theirbase.payment, &ci2->theirbase.payment));
	CHECK(pubkey_eq(&ci1->theirbase.delayed_payment, &ci2->theirbase.delayed_payment));
	CHECK(pubkey_eq(&ci1->remote_per_commit, &ci2->remote_per_commit));
	CHECK(pubkey_eq(&ci1->old_remote_per_commit, &ci2->old_remote_per_commit));
	CHECK(ci1->their_config.id != 0 && ci1->their_config.id == ci2->their_config.id);

	CHECK(c1->our_config.id != 0 && c1->our_config.id == c2->our_config.id);
	CHECK((lc1 != NULL) ==  (lc2 != NULL));
	if(lc1) {
		CHECK(lc1->newstate == lc2->newstate);
		CHECK(lc1->id == lc2->id);
	}

	CHECK((c1->last_tx != NULL) ==  (c2->last_tx != NULL));
	if(c1->last_tx) {
		CHECK(bitcoin_tx_eq(c1->last_tx, c2->last_tx));
	}
	CHECK(memeq(&c1->last_sig, sizeof(c1->last_sig),
		    &c2->last_sig, sizeof(c2->last_sig)));

	if (c1->remote_shutdown_scriptpubkey) {
		CHECK(c2->remote_shutdown_scriptpubkey);
		CHECK(c1->local_shutdown_idx == c2->local_shutdown_idx);
	}

	CHECK(c1->last_was_revoke == c2->last_was_revoke);

	return true;
}

static struct channel *wallet_channel_load(struct wallet *w, const u64 dbid)
{
	struct peer *peer;
	struct channel *channel;

	/* We expect only one peer, but reuse same code */
	if (!wallet_channels_load_active(w, w))
		return NULL;
	peer = list_top(&w->ld->peers, struct peer, list);
	CHECK(peer);

	/* We load lots of identical dbid channels: use last one */
	channel = list_tail(&peer->channels, struct channel, list);
	assert(channel->dbid == dbid);
	return channel;
}

static bool test_channel_crud(struct lightningd *ld, const tal_t *ctx)
{
	struct wallet *w = create_test_wallet(ld, ctx);
	struct channel c1, *c2 = tal(w, struct channel);
	struct peer *p;
	struct channel_info *ci = &c1.channel_info;
	struct bitcoin_txid *hash = tal(w, struct bitcoin_txid);
	struct pubkey pk;
	struct changed_htlc last_commit;
	secp256k1_ecdsa_signature *sig = tal(w, secp256k1_ecdsa_signature);
	u8 *scriptpubkey = tal_arr(ctx, u8, 100);

	memset(&c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(*c2));
	memset(ci, 3, sizeof(*ci));
	mempat(hash, sizeof(*hash));
	mempat(sig, sizeof(*sig));
	mempat(&last_commit, sizeof(last_commit));
	pubkey_from_der(tal_hexdata(w, "02a1633cafcc01ebfb6d78e39f687a1f0995c62fc95f51ead10a02ee0be551b5dc", 66), 33, &pk);
	ci->feerate_per_kw[LOCAL] = ci->feerate_per_kw[REMOTE] = 31337;
	mempat(scriptpubkey, tal_len(scriptpubkey));
	c1.first_blocknum = 1;
	p = new_peer(ld, 0, &pk, NULL);
	c1.peer = p;
	c1.dbid = wallet_get_channel_dbid(w);
	c1.state = CHANNELD_NORMAL;
	memset(&ci->their_config, 0, sizeof(struct channel_config));
	ci->remote_fundingkey = pk;
	ci->theirbase.revocation = pk;
	ci->theirbase.payment = pk;
	ci->theirbase.htlc = pk;
	ci->theirbase.delayed_payment = pk;
	ci->remote_per_commit = pk;
	ci->old_remote_per_commit = pk;
	/* last_tx taken from BOLT #3 */
	c1.last_tx = bitcoin_tx_from_hex(w, "02000000000101bef67e4e2fb9ddeeb3461973cd4c62abb35050b1add772995b820b584a488489000000000038b02b8003a00f0000000000002200208c48d15160397c9731df9bc3b236656efb6665fbfe92b4a6878e88a499f741c4c0c62d0000000000160014ccf1af2f2aabee14bb40fa3851ab2301de843110ae8f6a00000000002200204adb4e2f00643db396dd120d4e7dc17625f5f2c11a40d857accc862d6b7dd80e040047304402206a2679efa3c7aaffd2a447fd0df7aba8792858b589750f6a1203f9259173198a022008d52a0e77a99ab533c36206cb15ad7aeb2aa72b93d4b571e728cb5ec2f6fe260147304402206d6cb93969d39177a09d5d45b583f34966195b77c7e585cf47ac5cce0c90cefb022031d71ae4e33a4e80df7f981d696fbdee517337806a3c7138b7491e2cbb077a0e01475221023da092f6980e58d2c037173180e9a465476026ee50f96695963e8efe436f54eb21030e9f7b623d2ccc7c9bd44d66d5ce21ce504c0acf6385a132cec6d3c39fa711c152ae3e195220", strlen("02000000000101bef67e4e2fb9ddeeb3461973cd4c62abb35050b1add772995b820b584a488489000000000038b02b8003a00f0000000000002200208c48d15160397c9731df9bc3b236656efb6665fbfe92b4a6878e88a499f741c4c0c62d0000000000160014ccf1af2f2aabee14bb40fa3851ab2301de843110ae8f6a00000000002200204adb4e2f00643db396dd120d4e7dc17625f5f2c11a40d857accc862d6b7dd80e040047304402206a2679efa3c7aaffd2a447fd0df7aba8792858b589750f6a1203f9259173198a022008d52a0e77a99ab533c36206cb15ad7aeb2aa72b93d4b571e728cb5ec2f6fe260147304402206d6cb93969d39177a09d5d45b583f34966195b77c7e585cf47ac5cce0c90cefb022031d71ae4e33a4e80df7f981d696fbdee517337806a3c7138b7491e2cbb077a0e01475221023da092f6980e58d2c037173180e9a465476026ee50f96695963e8efe436f54eb21030e9f7b623d2ccc7c9bd44d66d5ce21ce504c0acf6385a132cec6d3c39fa711c152ae3e195220"));
	c1.last_sig = *sig;

	db_begin_transaction(w->db);
	CHECK(!wallet_err);

	wallet_channel_insert(w, &c1);

	/* Variant 1: insert with null for scid, last_sent_commit */
	wallet_channel_save(w, &c1);
	CHECK_MSG(!wallet_err,
		  tal_fmt(w, "Insert into DB: %s", wallet_err));
	CHECK_MSG(c2 = wallet_channel_load(w, c1.dbid), tal_fmt(w, "Load from DB"));
	CHECK_MSG(!wallet_err,
		  tal_fmt(w, "Load from DB: %s", wallet_err));
	CHECK_MSG(channelseq(&c1, c2), "Compare loaded with saved (v1)");
	tal_free(c2);

	/* We just inserted them into an empty DB so this must be 1 */
	CHECK(c1.dbid == 1);
	CHECK(c1.peer->dbid == 1);
	CHECK(c1.their_shachain.id == 1);

	/* Variant 2: update with scid set */
	c1.scid = talz(w, struct short_channel_id);
	c1.last_was_revoke = !c1.last_was_revoke;
	wallet_channel_save(w, &c1);
	CHECK_MSG(!wallet_err,
		  tal_fmt(w, "Insert into DB: %s", wallet_err));
	CHECK_MSG(c2 = wallet_channel_load(w, c1.dbid), tal_fmt(w, "Load from DB"));
	CHECK_MSG(!wallet_err,
		  tal_fmt(w, "Insert into DB: %s", wallet_err));
	CHECK_MSG(channelseq(&c1, c2), "Compare loaded with saved (v2)");
	tal_free(c2);

	/* Updates should not result in new ids */
	CHECK(c1.dbid == 1);
	CHECK(c1.peer->dbid == 1);
	CHECK(c1.their_shachain.id == 1);

	/* Variant 3: update with last_commit_sent */
	c1.last_sent_commit = &last_commit;
	wallet_channel_save(w, &c1);
	CHECK_MSG(!wallet_err, tal_fmt(w, "Insert into DB: %s", wallet_err));
	CHECK_MSG(c2 = wallet_channel_load(w, c1.dbid), tal_fmt(w, "Load from DB"));
	CHECK_MSG(!wallet_err,
		  tal_fmt(w, "Insert into DB: %s", wallet_err));
	CHECK_MSG(channelseq(&c1, c2), "Compare loaded with saved (v6)");
	tal_free(c2);

	/* Variant 4: update and add remote_shutdown_scriptpubkey */
	c1.remote_shutdown_scriptpubkey = scriptpubkey;
	c1.local_shutdown_idx = 1337;
	wallet_channel_save(w, &c1);
	CHECK_MSG(!wallet_err, tal_fmt(w, "Insert into DB: %s", wallet_err));
	CHECK_MSG(c2 = wallet_channel_load(w, c1.dbid), tal_fmt(w, "Load from DB"));
	CHECK_MSG(!wallet_err,
		  tal_fmt(w, "Insert into DB: %s", wallet_err));
	CHECK_MSG(channelseq(&c1, c2), "Compare loaded with saved (v8)");
	tal_free(c2);

	db_commit_transaction(w->db);
	CHECK(!wallet_err);
	tal_free(w);
	/* Normally freed by destroy_channel, but we don't call that */
	tal_free(p);
	return true;
}

static bool test_channel_config_crud(struct lightningd *ld, const tal_t *ctx)
{
	struct channel_config *cc1 = talz(ctx, struct channel_config),
			      *cc2 = talz(ctx, struct channel_config);
	struct wallet *w = create_test_wallet(ld, ctx);
	CHECK(w);

	cc1->dust_limit_satoshis = 1;
	cc1->max_htlc_value_in_flight_msat = 2;
	cc1->channel_reserve_satoshis = 3;
	cc1->htlc_minimum_msat = 4;
	cc1->to_self_delay = 5;
	cc1->max_accepted_htlcs = 6;

	CHECK(transaction_wrap(w->db, wallet_channel_config_insert(w, cc1)));
	CHECK_MSG(
	    cc1->id == 1,
	    tal_fmt(ctx, "channel_config->id != 1; got %" PRIu64, cc1->id));
	CHECK(transaction_wrap(w->db, wallet_channel_config_save(w, cc1)));

	CHECK(transaction_wrap(w->db, wallet_channel_config_load(w, cc1->id, cc2)));
	CHECK(memeq(cc1, sizeof(*cc1), cc2, sizeof(*cc2)));
       	return true;
}

static bool test_htlc_crud(struct lightningd *ld, const tal_t *ctx)
{
	struct htlc_in in, *hin;
	struct htlc_out out, *hout;
	struct preimage payment_key;
	struct channel *chan = tal(ctx, struct channel);
	struct peer *peer = talz(ctx, struct peer);
	struct wallet *w = create_test_wallet(ld, ctx);
	struct htlc_in_map *htlcs_in = tal(ctx, struct htlc_in_map);
	struct htlc_out_map *htlcs_out = tal(ctx, struct htlc_out_map);

	/* Make sure we have our references correct */
	CHECK(transaction_wrap(w->db,
			       db_exec(__func__, w->db, "INSERT INTO channels (id) VALUES (1);")));
	chan->dbid = 1;
	chan->peer = peer;

	memset(&in, 0, sizeof(in));
	memset(&out, 0, sizeof(out));
	memset(&in.payment_hash, 'A', sizeof(struct sha256));
	memset(&out.payment_hash, 'A', sizeof(struct sha256));
	memset(&payment_key, 'B', sizeof(payment_key));
	in.key.id = 42;
	in.key.channel = chan;
	in.msatoshi = 42;

	out.in = &in;
	out.key.id = 1337;
	out.key.channel = chan;
	out.msatoshi = 41;

	/* Store the htlc_in */
	CHECK_MSG(transaction_wrap(w->db, wallet_htlc_save_in(w, chan, &in)),
		  tal_fmt(ctx, "Save htlc_in failed: %s", wallet_err));
	CHECK_MSG(in.dbid != 0, "HTLC DB ID was not set.");
	/* Saving again should get us a collision */
	CHECK_MSG(!transaction_wrap(w->db, wallet_htlc_save_in(w, chan, &in)),
		  "Saving two HTLCs with the same data must not succeed.");
	CHECK(wallet_err);
	wallet_err = tal_free(wallet_err);

	/* Update */
	CHECK_MSG(transaction_wrap(w->db, wallet_htlc_update(w, in.dbid, RCVD_ADD_HTLC, NULL)),
		  "Update HTLC with null payment_key failed");
	CHECK_MSG(
		transaction_wrap(w->db, wallet_htlc_update(w, in.dbid, SENT_REMOVE_HTLC, &payment_key)),
	    "Update HTLC with payment_key failed");

	CHECK_MSG(transaction_wrap(w->db, wallet_htlc_save_out(w, chan, &out)),
		  tal_fmt(ctx, "Save htlc_out failed: %s", wallet_err));
	CHECK_MSG(out.dbid != 0, "HTLC DB ID was not set.");

	CHECK_MSG(!transaction_wrap(w->db, wallet_htlc_save_out(w, chan, &out)),
		  "Saving two HTLCs with the same data must not succeed.");
	CHECK(wallet_err);
	wallet_err = tal_free(wallet_err);

	/* Attempt to load them from the DB again */
	htlc_in_map_init(htlcs_in);
	htlc_out_map_init(htlcs_out);

	db_begin_transaction(w->db);
	CHECK(!wallet_err);

	CHECK_MSG(wallet_htlcs_load_for_channel(w, chan, htlcs_in, htlcs_out),
		  "Failed loading HTLCs");

	CHECK_MSG(wallet_htlcs_reconnect(w, htlcs_in, htlcs_out),
		  "Unable to reconnect htlcs.");
	db_commit_transaction(w->db);
	CHECK(!wallet_err);

	hin = htlc_in_map_get(htlcs_in, &in.key);
	hout = htlc_out_map_get(htlcs_out, &out.key);

	CHECK(hin != NULL);
	CHECK(hout != NULL);

	/* Have to free manually, otherwise we get our dependencies
	 * twisted */
	tal_free(hin);
	tal_free(hout);
	htlc_in_map_clear(htlcs_in);
	htlc_out_map_clear(htlcs_out);

	return true;
}

static bool test_payment_crud(struct lightningd *ld, const tal_t *ctx)
{
	struct wallet_payment *t = tal(ctx, struct wallet_payment), *t2;
	struct wallet *w = create_test_wallet(ld, ctx);

	mempat(t, sizeof(*t));
	memset(&t->destination, 1, sizeof(t->destination));

	t->id = 0;
	t->msatoshi = 100;
	t->status = PAYMENT_PENDING;
	t->payment_preimage = NULL;
	memset(&t->payment_hash, 1, sizeof(t->payment_hash));

	db_begin_transaction(w->db);
	wallet_payment_setup(w, tal_dup(NULL, struct wallet_payment, t));
	wallet_payment_store(w, &t->payment_hash);
	t2 = wallet_payment_by_hash(ctx, w, &t->payment_hash);
	CHECK(t2 != NULL);
	CHECK(t2->status == t->status);
	CHECK(pubkey_cmp(&t2->destination, &t->destination) == 0);
	CHECK(t2->msatoshi == t->msatoshi);
	CHECK(!t2->payment_preimage);

	t->status = PAYMENT_COMPLETE;
	t->payment_preimage = tal(w, struct preimage);
	memset(t->payment_preimage, 2, sizeof(*t->payment_preimage));
	wallet_payment_set_status(w, &t->payment_hash, t->status,
				  t->payment_preimage);
	t2 = wallet_payment_by_hash(ctx, w, &t->payment_hash);
	CHECK(t2 != NULL);
	CHECK(t2->status == t->status);
	CHECK(pubkey_cmp(&t2->destination, &t->destination) == 0);
	CHECK(t2->msatoshi == t->msatoshi);
	CHECK(structeq(t->payment_preimage, t2->payment_preimage));

	db_commit_transaction(w->db);
	return true;
}

int main(void)
{
	bool ok = true;
	tal_t *tmpctx = tal_tmpctx(NULL);
	struct lightningd *ld = tal(tmpctx, struct lightningd);

	/* Only elements in ld we should access */
	list_head_init(&ld->peers);
	pubkey_from_der(tal_hexdata(tmpctx, "02a1633cafcc01ebfb6d78e39f687a1f0995c62fc95f51ead10a02ee0be551b5dc", 66), 33, &ld->id);
	/* Accessed in peer destructor sanity check */
	htlc_in_map_init(&ld->htlcs_in);
	htlc_out_map_init(&ld->htlcs_out);

	ok &= test_wallet_outputs();
	ok &= test_shachain_crud();
	ok &= test_channel_crud(ld, tmpctx);
	ok &= test_channel_config_crud(ld, tmpctx);
	ok &= test_htlc_crud(ld, tmpctx);
	ok &= test_payment_crud(ld, tmpctx);

	tal_free(tmpctx);
	return !ok;
}
