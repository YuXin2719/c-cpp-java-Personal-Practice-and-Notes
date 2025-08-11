package com.easyjava.entity.query;



/**
 * @description:角色表查询对象
 * @Author:YuXin
 * @date:2025/02/26
 */
public class NpcOtherQuery {
	/**
	 * 主键
	 */
	private Integer id;

	/**
	 * 姓名
	 */
	private String name;

	private String nameFuzzy;

	/**
	 * 性别
	 */
	private String sex;

	private String sexFuzzy;

	/**
	 * 出生年
	 */
	private Integer birth;

	/**
	 * 登场年
	 */
	private Integer appear;

	/**
	 * 死亡年
	 */
	private Integer death;

	/**
	 * 统帅
	 */
	private Integer ts;

	/**
	 * 武力
	 */
	private Integer wl;

	/**
	 * 智力
	 */
	private Integer zl;

	/**
	 * 政治
	 */
	private Integer zz;

	/**
	 * 魅力
	 */
	private Integer ml;

	/**
	 * 总和
	 */
	private Integer total;

	/**
	 * 势力
	 */
	private String shili;

	private String shiliFuzzy;

	public void setId(Integer id) {
		this.id = id;
	}

	public Integer getId() {
		return this.id;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getSex() {
		return this.sex;
	}

	public void setBirth(Integer birth) {
		this.birth = birth;
	}

	public Integer getBirth() {
		return this.birth;
	}

	public void setAppear(Integer appear) {
		this.appear = appear;
	}

	public Integer getAppear() {
		return this.appear;
	}

	public void setDeath(Integer death) {
		this.death = death;
	}

	public Integer getDeath() {
		return this.death;
	}

	public void setTs(Integer ts) {
		this.ts = ts;
	}

	public Integer getTs() {
		return this.ts;
	}

	public void setWl(Integer wl) {
		this.wl = wl;
	}

	public Integer getWl() {
		return this.wl;
	}

	public void setZl(Integer zl) {
		this.zl = zl;
	}

	public Integer getZl() {
		return this.zl;
	}

	public void setZz(Integer zz) {
		this.zz = zz;
	}

	public Integer getZz() {
		return this.zz;
	}

	public void setMl(Integer ml) {
		this.ml = ml;
	}

	public Integer getMl() {
		return this.ml;
	}

	public void setTotal(Integer total) {
		this.total = total;
	}

	public Integer getTotal() {
		return this.total;
	}

	public void setShili(String shili) {
		this.shili = shili;
	}

	public String getShili() {
		return this.shili;
	}

	public void setNameFuzzy(String nameFuzzy) {
		this.nameFuzzy = nameFuzzy;
	}

	public String getNameFuzzy() {
		return this.nameFuzzy;
	}

	public void setSexFuzzy(String sexFuzzy) {
		this.sexFuzzy = sexFuzzy;
	}

	public String getSexFuzzy() {
		return this.sexFuzzy;
	}

	public void setShiliFuzzy(String shiliFuzzy) {
		this.shiliFuzzy = shiliFuzzy;
	}

	public String getShiliFuzzy() {
		return this.shiliFuzzy;
	}

}