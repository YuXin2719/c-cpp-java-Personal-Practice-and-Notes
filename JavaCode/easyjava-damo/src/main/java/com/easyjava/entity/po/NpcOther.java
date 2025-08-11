package com.easyjava.entity.po;

import java.io.Serializable;


/**
 * @description:角色表
 * @Author:YuXin
 * @date:2025/02/26
 */
public class NpcOther implements Serializable {
	/**
	 * 主键
	 */
	private Integer id;

	/**
	 * 姓名
	 */
	private String name;

	/**
	 * 性别
	 */
	private String sex;

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

	@Override
	public String toString() {
		return "主键:" + (id == null ? "空" : id) + ",姓名:" + (name == null ? "空" : name) + ",性别:" + (sex == null ? "空" : sex) + ",出生年:" + (birth == null ? "空" : birth) + ",登场年:" + (appear == null ? "空" : appear) + ",死亡年:" + (death == null ? "空" : death) + ",统帅:" + (ts == null ? "空" : ts) + ",武力:" + (wl == null ? "空" : wl) + ",智力:" + (zl == null ? "空" : zl) + ",政治:" + (zz == null ? "空" : zz) + ",魅力:" + (ml == null ? "空" : ml) + ",总和:" + (total == null ? "空" : total) + ",势力:" + (shili == null ? "空" : shili);
	}
}